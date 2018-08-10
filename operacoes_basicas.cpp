#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define ll long long

string add(string n1, string n2){
	return "a";
}

string mul(string n1, string n2, string m){
	cout << n1 << endl << n2 << endl << m << endl;
	if(n2 == "-" || n2 == "")
		return m;
	int i = n2.size()-1, zeros = 0;
	for(; i > 0 && n2[i] == '0'; i--, zeros++);
	int last = n2[i];
	while(last--)
		m = add(m, n1+string(zeros, '0'));
	return mul(n1, string(n2.begin(), n2.end()-1), m);
}

int main(){

	ios::sync_with_stdio(false); cout << fixed << setprecision(3);

	string op, n1, n2;
	cin >> op >> n1 >> n2;

	if(op[2] == 'M')
		cout << add(n1, n2) << endl;
	else if(op[2] == 'B')
		cout << add(n1, "-"+n2) << endl;
	else if(op[2] == 'L')
		cout << mul(n1, n2, "0") << endl;
	else if(op[2] == 'V')
		cout << mul(n1, n2, "0") << endl;
}
