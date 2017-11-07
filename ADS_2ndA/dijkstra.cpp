#include <iostream>


	using namespace std;

	int main() {
		int sz;
		cin >> sz;
 		int a[sz][sz];
		int d[sz];
		int v[sz];
		int temp;
		int minindex, mini;

		for(int i = 0; i < sz; i++) {
			a[i][i] = 0;
			for(int j = i + 1; j < sz; j++) {
				printf("Enter %d - %d: ", i + 1, j + 1);
				scanf("%d", &temp);
				a[i][j] = temp;
				a[j][i] = temp;
			}
		}

		for(int i = 0; i < sz; i++) {
			for(int j = 0; j < sz; j++) 
				printf("%5d", a[i][j]);
				printf("\n");
			}


		for(int i = 0; i < sz; i++) {
			d[i] = 10000;
			v[i] = 1;
		}
		d[0] = 0;


		do {
			minindex = 10000;
			mini = 10000;

			for(int i = 0; i < sz; i++) {
				if((v[i] == 1) && (d[i] < mini)) {
					mini = d[i];
					minindex = i;

				}
			}


		if(minindex != 10000) {
			for(int i = 0; i < sz; i++) {
				if(a[minindex][i] > 0) {
					temp = mini + a[minindex][i];
					if(temp < d[i])
						d[i] = temp;
				}
			}
			v[minindex] = 0;
		}
		}
		while(minindex < 10000);

		for(int i = 0; i < sz; i++) 
			printf("%5d \n", d[i]);
			getchar(); getchar();



	   return 0;
	   }