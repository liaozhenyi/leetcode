/**********************************************************************

 Given n points on a 2D plane, find the maximum number of points that
  lie on the same straight line.

**********************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point> &points) {
	int maxp = 0, cnt, same_cnt;
	double k;
	std::map<double, int> hash;

	for (vector<Point>::size_type i = 0; i < points.size(); i++) {
		same_cnt = 1;
		cnt = 0;
		hash.erase(hash.begin(), hash.end());
		for (vector<Point>::size_type j = 0; j < points.size(); j++) {
			if (i == j)
				continue;
			if (points[j].x == points[i].x && \
				points[j].y == points[i].y) {
				++same_cnt;
				continue;
			}
			if (points[j].x == points[i].x) {
				++cnt;
				continue;
			}

			k = ((double)points[j].y-points[i].y) / \
				((double)points[j].x-points[i].x);
			std::map<double, int>::iterator it;
			it = hash.find(k);
			if (it == hash.end()) {
				hash.insert(std::pair<double, int>(k, 1));
			} else {
				++(it->second);
			}
		}
		for (auto m: hash) {
			if (m.second+same_cnt > maxp) {
				maxp = m.second+same_cnt;
			}
		}
		if (cnt+same_cnt > maxp)
			maxp = cnt+same_cnt;
	}

	return maxp;
}

int main(void)
{
	std::vector<Point> points;
	vector<int> X = {0,1,1};
	vector<int> Y = {0,1,-1};
	
	for (vector<int>::size_type i = 0; i < X.size(); i++)
		points.push_back(Point(X[i], Y[i]));

	std::cout << maxPoints(points) << std::endl;
	
	return 0;
}
