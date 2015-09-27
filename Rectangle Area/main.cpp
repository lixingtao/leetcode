#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

struct Segment {
	int l;
	int r;
	int h;
	int tag;
};

int cmp(const void *a, const void *b) {
	return ((struct Segment *)a)->h - ((struct Segment *)b)->h;
}

int get_line(vector<vector<int> > vet) {
	if (vet.size() == 0) return 0;
	if (vet.size() == 1) return vet[0][1] -vet[0][0];
	if ((vet[0][0] <= vet[1][0] && vet[0][1] >= vet[1][0]) || (vet[0][0] >= vet[1][0] && vet[1][1] >= vet[0][0])) {
		return max(vet[0][1], vet[1][1]) - min(vet[0][0], vet[1][0]);
	}
	else return vet[0][1] - vet[0][0] + vet[1][1] - vet[1][0];
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	Segment seg[4] = {{A, C, B, -1}, {A, C, D, 1}, {E, G, F, -1}, {E, G, H, 1}};
	qsort(seg, 4, sizeof(Segment), cmp);
	/*for (int i = 0; i < 4; i++) {
		printf("%d\t%d\t%d\t%d\n", seg[i].l, seg[i].r, seg[i].h, seg[i].tag);
	}*/
	//seg[0] = {A, C, B, -1};
	vector<vector<int> > under_line;
	int high = 1<<31;
	int sum  = 0;
	for (int i = 0; i < 4; i++) {
		int len = get_line(under_line);
		sum += (seg[i].h - high) * len;
		high = seg[i].h;

		vector<int> tmp;
		tmp.push_back(seg[i].l);
		tmp.push_back(seg[i].r);

		if (seg[i].tag == -1) under_line.push_back(tmp);
		else {
			for (vector<vector<int> >::iterator it = under_line.begin(); it != under_line.end(); it++) {
				if ((*it)[0] == seg[i].l && (*it)[1] == seg[i].r) {
					under_line.erase(it);
					break;
				}
			}
		}
	}
	return sum;
}

int main()
{
	//int ans = computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
	int ans = computeArea(-2, -2, 2, 2, -2, -2, 2, 2);
	cout<<ans<<endl;
	return 0;
}
