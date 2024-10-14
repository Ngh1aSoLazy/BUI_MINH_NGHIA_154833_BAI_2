#include<iostream>
#include<math.h>

/*
	Thiết kế giải thuật và cài đặt để tạo ra một mảng số nửa nguyên tố (Blum) 
	nhỏ hơn một số N cho trước và thực hiện hai yêu cầu sau:
	- Tìm ra tất cả các cặp số Blum có tổng cũng là một số Blum nhỏ hơn N
	- Kiểm tra xem một số Blum M có tồn tại trong dãy số Blum được tạo ra hay không.
*/

using namespace std;

// Biến toàn cục
int a = 0;
int b = 0;

// Hàm kiểm tra số nguyên tố 
bool FIND_PRIME(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

// Hàm tạo mảng các số nguyên tố
int LIST(int arr[], int n)
{
	for (int i = 2; i < n; i++)
	{
		if (FIND_PRIME(i) == true)
		{
			arr[a] = i;
			a++;
		}
	}

	return 0;
}

// Hàm tạo mảng các số blum được tạo ra từ mảng số nguyên tố vừa tìm được
void LIST2(int arr[], int arr2[], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] * arr[j] < m)
			{
				arr2[b] = arr[i] * arr[j];
				b++;
			}
		}
	}
}

// Hàm kiểm tra 1 số blum có tồn tại hay không
bool FIND_BLUM(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == n) return true;
	}
	return false;
}

// Hàm tìm ra cặp số blum trong mảng có tổng cũng là 1 số blum < n
void FIND_PAIR(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			sum = arr[i] + arr[j];
			for (int k = 0; k < n; k++)
			{
				if (sum == arr[k])
				{
					cout << "Pair is: [" << i << ", " << j << "]" << endl;
				}
			}
		}
	}
}

int main()
{
	// Nhập giới hạn n
	int n;
	cin >> n;

	// Cấp phát mảng động để lưu giá trị của các số nguyên tố và số nửa nguyên tố
	int* arr = new int[a];
	int* arr2 = new int[b];

	// Hàm tạo mảng các số nguyên tố < n
	LIST(arr, n); 

	// In ra màn hình các số nguyên tố trong mảng
	cout << "Prime numbers: {";
	for (int i = 0; i < a; i++)
	{
		cout << ", " << arr[i];
	}
	cout << "}" << endl;

	// Hàm tạo mảng các số nửa nguyên tố < n
	LIST2(arr, arr2, a, n);

	// In ra màn hình các số nửa nguyên tố trong mảng
	cout << "Semiprime numbers: {";
	for (int i = 0; i < b; i++)
	{
		cout << " " << arr2[i];
	}
	cout << "}" << endl;

	// Khai báo biến lưu giá trị cần tìm
	cout << "Find? ";
	int num;
	cin >> num;

	// Hàm xác định có tồn tại hay không số nửa nguyên tố nhập vào
	if (FIND_BLUM(arr2, num)) cout << "Found!" << endl;
	else cout << "Not found!" << endl;

	// Hàm tìm cặp số nửa nguyên tố có tổng cũng là số nửa nguyên tố < n
	FIND_PAIR(arr2, b);

	return 0;
}