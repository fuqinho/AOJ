#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#define INF 10000000
#define I64 long long int
#define FOR(a,start,end) for(I64 a=(start);a<(end);a++)
using namespace std;

int main(){
	int vec[] = {1, -1, 4, -4};
	queue<string> que;
	que.push("01234567");

	map<string, int> d;

	while(!que.empty()){
		string str = que.front();
		que.pop();
		int zero = str.find("0");

		string str2;
		FOR(i, 0, 4){
			int next_z;
			next_z = zero + vec[i];
			if(next_z >= 0 && next_z <= 7 && !((zero == 3 && next_z == 4) || (zero == 4 && next_z == 3))){
				str2 = str;
				swap(str2[zero], str2[next_z]);
				if(d.find(str2) == d.end()){
					que.push(str2);
					d[str2] = d[str] + 1;
				}
			}
		}
	}

	string num;
	while(getline(cin, num)){
		string::iterator end_it = remove(num.begin(), num.end(), ' ');
		num.erase(end_it, num.end());
		cout << d[num] << endl;
	}
}
