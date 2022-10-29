'''Find the duplicate element in a limited range array.
Given a limited range array of size n containing elements between 1 and n-1 with one element repeating,
find the duplicate number in it without using any extra space.'''

'''Ý tưởng: giả sử quan sát con trỏ 'p' đang ở 0, chạy vòng lặp while khi con trỏ p đạt đến giá trị n. 
Nếu giá trị của a [p] là -1 thì tăng con trỏ lên 1 và bỏ qua bước lặp.
Ngược lại, chuyển đến vị trí của phần tử mà con trỏ hiện tại đang trỏ đến, tức là tại a [p].
Nếu giá trị tại a [p] tức là a [a [p]] là -1 thì hãy ngắt vòng lặp vì phần tử a [p] là phần tử trùng lặp.
Nếu không, lưu giá trị của a [a [p]] trong a [p] tức là a [p] = a [a [p]] và đặt -1 trong [a [p]] tức là a [a [p]] = -1.'''

#include <iostream>
using namespace std;

void find_duplicate(int a[], int n)
{
	int p = 0;
	while (p != n) {
		if (a[p] == -1) {
			p++;
		}
		else {
			if (a[a[p] - 1] == -1) {
				cout << a[p] << endl;
				break;
			}
			else {
				a[p] = a[a[p] - 1];
				a[a[p] - 1] = -1;
			}
		}
	}
}

int main()
{
	int a[] = { 1, 2, 4, 3, 4};
	int n = sizeof(a) / sizeof(a[0]);
	find_duplicate(a, n);
	return 0;
}

