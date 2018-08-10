#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>

using namespace std;
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define ll long long

int main(){

	ios::sync_with_stdio(false); cout << fixed << setprecision(3);

	int n;
	double x, y;
	pair<double,double> rabbit, fox;
	vector< pair<double,double> > holes;

	cin >> n >> x >> y;
	rabbit.first = x;
	rabbit.second = y;
	cin >> x >> y;
	fox.first = x;
	fox.second = y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		holes.pb(mp(x,y));
	}

	for(pair<double,double> hole : holes){
		double distRab = sqrt(pow(hole.first-rabbit.first,2)+pow(hole.second-rabbit.second,2));
		double distFox = sqrt(pow(hole.first-fox.first,2)+pow(hole.second-fox.second,2));
		if(2*distRab < distFox){
			cout << "O coelho pode escapar pelo buraco (" << hole.first << "," << hole.second << ").\n";
			return 0;
		}
	}
	cout << "O coelho nao pode escapar.\n";
	return 0;

}
