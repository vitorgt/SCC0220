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

	cin >> n >> x >> y;
	rabbit.first = x;
	rabbit.second = y;
	cin >> x >> y;
	fox.first = x;
	fox.second = y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		double distRab = sqrt(pow(x-rabbit.first,2)+pow(y-rabbit.second,2));
		double distFox = sqrt(pow(x-fox.first,2)+pow(y-fox.second,2));
		if(2*distRab < distFox){
			cout << "The rabbit can escape through the hole (" << x << "," << y << ").\n";
			return 0;
		}
	}
	cout << "The rabbit can't escape.\n";
	return 0;

}
