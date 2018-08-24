#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
#include<cstdlib>

using namespace std;
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define ll long long

string add(string n1, string n2);

string sub(string n1, string n2){
	if((n1[0] == '-') != (n2[0] == '-')){// XOR
		/* If both of them are positives, subtract.
		 * if both of them are negatives, subtract.
		 * if one is posituve and the other negative, sum.
		 */
		if(n1[0] == '-')
			return "-"+add(string(n1.begin()+1, n1.end()), n2);
		return "-"+add(n1, string(n2.begin()+1, n2.end()));
	}

	bool bothNegatives = false;
	if((n1[0] == '-') && (n2[0] == '-'))
		bothNegatives = true;

	if(n1[0] == '-')
		n1 = string(n1.begin()+1, n1.end());
	if(n2[0] == '-')
		n2 = string(n2.begin()+1, n2.end());

	string sub = "";
	if(n1.length() > n2.length())
		// complete the number with zeros on the left
		// so both of them have the same size now
		n2.insert(0, abs((int)n1.length() - (int)n2.length()), '0');
	else
		n1.insert(0, abs((int)n1.length() - (int)n2.length()), '0');
	int carry = 0;
	for(int i = n1.length()-1; i >= 0; i--){
		int digit = (n1[i]-'0') - (n2[i]-'0') - carry;
		if(digit < 0){
			digit += 10;
			carry = 1;
		}
		else
			carry = 0;
		sub.pb(digit+'0');
	}
	if(bothNegatives)
		sub.pb('-');
	string subRe = "";
	for(int i = sub.length()-1; i >= 0; i--){
		subRe.pb(sub[i]);
	}
	return subRe;
}

string add(string n1, string n2){
	if((n1[0] == '-') != (n2[0] == '-'))// XOR
		/* If both of them are positives, sum.
		 * if both of them are negatives, sum.
		 * if one is posituve and the other negative, subtract.
		 */
		return sub(n1, n2);

	bool bothNegatives = false;
	if((n1[0] == '-') && (n2[0] == '-'))
		bothNegatives = true;

	if(n1[0] == '-')
		n1 = string(n1.begin()+1, n1.end());
	if(n2[0] == '-')
		n2 = string(n2.begin()+1, n2.end());

	string sum = "";
	if(n1.length() > n2.length())
		// complete the number with zeros on the left
		// so both of them have the same size now
		n2.insert(0, abs((int)n1.length() - (int)n2.length()), '0');
	else
		n1.insert(0, abs((int)n1.length() - (int)n2.length()), '0');
	int carry = 0;
	for(int i = n1.length()-1; i >= 0; i--){
		int digit = (n1[i]-'0') + (n2[i]-'0') + carry;
		sum.pb(digit%10+'0');
		carry = digit/10;
	}
	if(carry)
		sum.pb(carry+'0');
	if(bothNegatives)
		sum.pb('-');
	string sumRe = "";
	for(int i = sum.length()-1; i >= 0; i--){
		sumRe.pb(sum[i]);
	}
	return sumRe;
}

string mul(string n1, string n2, string m){
	if(n2[0] == '0')
		return m;
	int i, zeros = 0;
	for(i = n2.size()-1; i >= 0 && n2[i] == '0'; i--, zeros++);
	int last = n2[i]-'0';
	while(last--)
		m = add(m, n1+string(zeros, '0'));
	return mul(n1, string(n2.begin(), n2.end()-(1+zeros))+string(1+zeros, '0'), m);
}

int main(){

	ios::sync_with_stdio(false); cout << fixed << setprecision(3);

	string op, n1, n2;
	cin >> op >> n1 >> n2;

	if(op[2] == 'M')
		cout << add(n1, n2) << endl;
	else if(op[2] == 'B')
		cout << sub(n1, n2) << endl;
	else if(op[2] == 'L'){
		bool xorNegatives = false;
		if((n1[0] == '-') != (n2[0] == '-'))
			xorNegatives = true;
		if(n1[0] == '-')
			n1 = string(n1.begin()+1, n1.end());
		if(n2[0] == '-')
			n2 = string(n2.begin()+1, n2.end());
		cout << (xorNegatives?"-":"") + mul(n1, n2, "") << endl;
	}
	else if(op[2] == 'V')
		cout << mul(n1, n2, "") << endl;
}
