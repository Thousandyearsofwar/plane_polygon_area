
#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
class point {
private:
	int x;
	int y;
public:
	point() :x(0),y(0){}
	point(int x1, int y1): x(x1), y(y1) {}
	void setx_y() { cin>>this->x>> this->y; }
	int getx() { return x; }
	int gety() { return y; }
};
template<class T>
void caculate(T first,T last) {
	float k,b,delta_x, delta_y,area = 0;
	point beginpoint=(*first);
	for (; first!= last; ++first){
		if ((first + 1) == last) {
			float last_x =  (*first).getx()- beginpoint.getx();
			float last_y =  (*first).gety()- beginpoint.gety();
			if (last_x == 0) {
				printf("%.1f\n", -area);
				area = 0;
				break;
			}
			k = last_y / last_x;
			b = (*first).gety() - k * ((*first).getx());
			area += k / 2 * pow(last_x, 2) + b * last_x;
			printf("%.1f\n", -area);
			area = 0;
			break;
		}
			delta_x =  (*first).getx()-(*(first + 1)).getx();
			delta_y =  (*first).gety()- (*(first + 1)).gety();
			if (delta_x == 0)
				continue;
			k = delta_y / delta_x;
			b = (*first).gety() - k * ((*first).getx());
			area += (k/2 * (*(first + 1)).getx()+b* (*(first + 1)).getx()) - (k / 2 * (*first).getx() + b * (*first).getx());
	}
}
int main()
{
	int pointnum;
	cin >> pointnum;
	vector<vector<point>>sample;
	while (true) {
		vector<point>  *polygon=new vector<point>;
		point *temp = new point();
		while (pointnum != 0) {
			(*temp).setx_y();
			(*polygon).push_back(*temp);
			pointnum--;
		}
		sample.push_back(*polygon);
		cin >> pointnum;
		if (pointnum == 0) {
			vector<vector<point>>::iterator iter = sample.begin();
			for (; iter != sample.end(); ++iter)
				caculate((*iter).begin(), (*iter).end());
			break;
		}
	}
	return 0;
}
