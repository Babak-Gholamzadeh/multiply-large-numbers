#include <iostream>

using namespace std;

int main()
{
	int a[100], b[100], acount, bcount, carry, s[200], sp, i, j, temp;
	char ch[100];
	cout << "Enter first number:";
	cin >> ch;
	for (i=0; i<100; i++)
		if (ch[i] == '\0')
		{
			acount = (i-1);
			i--;
			for (j=0; j<=acount; j++)
				a[j] = ch[i--] - 48;
			break;
		}
	cout << "a=";
	for (i=acount; i>=0; i--)
		cout << a[i];
	cout << endl << "acount = " << acount << endl;
	for (i=0; i<100; i++)
		ch[i] = '\0';
	cout << "Enter second number:";
	cin >> ch;
	for (i=0; i<100; i++)
		if (ch[i] == '\0')
		{
			bcount = (i-1);
			i--;
			for (j=0; j<=bcount; j++)
				b[j] = ch[i--] - 48;
			break;
		}
	cout << "b=";
	for (i=bcount; i>=0; i--)
		cout << b[i];
	cout << endl << "bcount = " << bcount << endl;

	for (i=0; i<200; i++)
		s[i] = 0;

	for (i=0; i<=bcount; i++)
	{
		sp = i;
		carry = 0;
		for (j=0; j<=acount; j++)
		{
			temp = s[sp]+((b[i]*a[j]+carry)%10);
			s[sp] = temp % 10;
			s[sp+1] += temp / 10;
			carry = (b[i]*a[j]+carry)/10;
			sp++;
		}
		s[sp] += carry;
	}
	cout << "Result mul = ";
	for (i=sp; i>=0; i--)
		cout << s[i];
	cout << "\nsp=" << sp;
	return 0;
}
