#include <vector>
#include <cmath>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

struct Point {
    int x;
    int y;
    Point():x(0),y(0){}
    Point(int a,int b):x(a),y(b){}
};

bool equal(double x,double y){
    if(fabs(x-y)<10e-6)return true;
    return false;
}

int maxPoints(vector<Point> &points){
    int len=points.size();
    if(len<=2)return len;

    double slope[len];/// 存储斜率
    int ma=0;
    for(int i=0;i<len-1;i++){
	int vertical =1;///与i点垂直方向上的点数，因为这个时候dx==0不能计算斜率，要单独计算
	int samePoint=1;///与i点在同一位置上的点的个数
	int cnt=0;
	for(int j=i+1;j<len;j++){
	    int dx=points[i].x-points[j].x;
	    int dy=points[i].y-points[j].y;
	    if(dx==0){
		if(dy==0) samePoint++;
		else vertical++;
	    }
	    else slope[cnt++]=(double)dy/dx;
	}

	ma=max(ma,vertical+samePoint-1);///减1，因为在vertical和samePoint中都包含i点
	if(cnt==0)return ma;

	sort(slope,slope+cnt);
	int repCnt=1+samePoint;
	for(int j=1;j<cnt;j++){
	    if(equal(slope[j],slope[j-1]))repCnt++;
	    else {
		ma=max(ma,repCnt);
		repCnt=1+samePoint;
	    }
	}
	if(repCnt>ma)ma=repCnt;
    }
    return ma;
}
int main(){
    freopen("in.dat","r",stdin);
    vector<Point>points;
    int x,y;
    while(cin>>x>>y){
	Point *a=new Point(x,y);
	points.push_back(*a);
    }
    cout<<maxPoints(points)<<endl;
    return 0;
}
