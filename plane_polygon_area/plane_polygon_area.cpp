#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
class point {
private:
	int x;
	int y;
public:
	point() :x(0), y(0) {}
	point(int x1, int y1) : x(x1), y(y1) {}
	void setx_y() { scanf_s("%d%d", &this->x,&this->y); }
	int getx() { return x; }
	int gety() { return y; }
};
template<class T, class T1>
void caculate(T begin, T end, T1 first) {
	float delta_a, delta_b, area = 0;
	for (; begin != end; ++begin) {
		T1 first = (*begin).begin();
		T1 last = (*begin).end();
		point beginpoint = (*first);
			for (; first != last; ++first ) {
				if ((first + 1) == last) {
					float last_a = (*first).getx()*beginpoint.gety();
					float last_b = beginpoint.getx() *(*first).gety();
					area += (last_a- last_b)/2.0;
					printf("%.1f\n", abs(area));
					area = 0;
					break;
				}
				delta_a = (*first).getx() * (*(first + 1)).gety();
				delta_b = (*(first + 1)).getx()*(*first).gety() ;
				area += (delta_a - delta_b) / 2.0;
			}

	}

}
int main()
{
	int pointnum;
	scanf_s("%d",&pointnum);
	vector<vector<point>>sample;
	while (pointnum < 3 || pointnum>100) {
		scanf_s("%d", &pointnum);
		if (pointnum == 0)
			return 0;
	}
	while (true) {
		vector<point>  *polygon = new vector<point>;
		point *temp = new point();
		while (pointnum != 0) {
			(*temp).setx_y();
			(*polygon).push_back(*temp);
			pointnum--;
		}
		sample.push_back(*polygon);
		while (pointnum < 3 || pointnum>100){
			scanf_s("%d", &pointnum);
			if (pointnum == 0) {
				caculate(sample.begin(), sample.end(), (*sample.begin()).begin());
				return 0;
			}
		}
	}
}