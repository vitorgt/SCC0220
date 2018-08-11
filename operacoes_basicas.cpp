#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define ll long long

string add(string n1, string n2){
    if((n1[0] == '-') != (n2[0] == '-'))// XOR
        /* If both of them are positives, sum.
         * if both of them are negatives, sum.
         * if one is posituve and the other negative, subtract.
         */
        return sub(n1, n2);
    string sum = "";
    if(n1.length() > n2.length())
        // complete the number with zeros on the left
        // so both of them have the same size now
        n2.insert(0, abs(n1.length() - n2.length()), '0');
    else
        n1.insert(0, abs(n1.length() - n2.length()), '0');
    int carry = 0;
    for(int i = n1.length()-1; i > 0; i--){
        
    }
}

string add(string str1, string str2){
    // Traverse from end of both strings
    for (int i=n1-1; i>=0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining digits of str2[]
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
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
		cout << sub(n1, n2) << endl;
	else if(op[2] == 'L')
		cout << mul(n1, n2, "0") << endl;
	else if(op[2] == 'V')
		cout << mul(n1, n2, "0") << endl;
}
