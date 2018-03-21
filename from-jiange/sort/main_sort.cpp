#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Sort {
public:
	void swap(int &a, int &b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	// 1. ð������
	void BubbleSort(vector<int> &nums) {
		int n = nums.size();
		for (int i = 1; i < n; i++) {  // i��ʾð�ݵ�������������Ҫn-1��
			int flag = 0;  // flag��ʾĳ��ð���Ƿ��н���Ԫ��
			for (int j = 0; j < n - i; j++) {
				if (nums[j] > nums[j + 1]) {
					swap(nums[j], nums[j + 1]);
					flag = 1;
				}
			}
			if (flag == 0) break;  // ĳ�˽������ж��Ƿ�������
		}
	}

	// 2. ѡ������
	void SelectSort(vector<int> &nums) {
		int n = nums.size();
		for (int i = 0; i < n - 1; i++) {  // i��ʾ������������˵�Ԫ��
			int index = i;
			for (int j = i + 1; j < n; j++)  // �ҳ�������������ֵ��С���±�
				if (nums[j] < nums[index])
					index = j;
			swap(nums[i], nums[index]);
		}
	}

	// 3. ��������
	// 3.1 ֱ�Ӳ�������
	void InsertSort(vector<int> &nums) {
		int n = nums.size();
		for (int i = 1; i < n; i++) {  // �ӵڶ���Ԫ�ؿ�ʼ��������ǰ����
			int tmp = nums[i], j = i - 1;
			for (; j >= 0 && tmp < nums[j]; j--)  // Ѱ��tmp����ȷλ�ã�����ȷʱ������Ԫ�غ���
				nums[j + 1] = nums[j];
			nums[j + 1] = tmp;
		}
	}

	// 3.2 �۰��������
	void InsertSort2(vector<int> &nums) {
		int n = nums.size();
		for (int i = 1; i < n; i++) {
			int tmp = nums[i];
			// �۰���ң�����ʱ��low��Ϊtmp����ȷλ��
			int high = i - 1, low = 0, mid;
			while (low <= high) {
				mid = (low + high) / 2;
				if (tmp < nums[mid]) high = mid - 1;
				else low = mid + 1;
			}
			// ��low�����Ԫ�ض�������һλ
			for (int j = i; j > low; j--) {
				nums[j] = nums[j - 1];
			}
			nums[low] = tmp;
		}
	}

	// 4. �鲢����
	// �����������ϲ������������У�ֻ������ʼλ�ã��ֽ��ߣ��Լ��յ�λ��
	void Merge(vector<int> &nums, int start, int mid, int end) {
		int i = start, j = mid + 1;
		vector<int> ret;
		while (i <= mid && j <= end) {
			if (nums[i] < nums[j]) {
				ret.push_back(nums[i]);
				i++;
			}
			else {
				ret.push_back(nums[j]);
				j++;
			}
		}
		while (i <= mid) {
			ret.push_back(nums[i]);
			i++;
		}
		while (j <= end) {
			ret.push_back(nums[j]);
			j++;
		}
		// �ϲ���ɺ󣬰ѽ���Ż�nums��ͬһ������
		for (int i = start; i <= end; i++) {
			nums[i] = ret[i - start];
		}
	}

	// �ݹ�ؽ��й鲢
	void MergeSort(vector<int> &nums, int start, int end) {
		if (start < end) {
			int mid = (start + end) / 2;
			MergeSort(nums, start, mid);		// ��벿������
			MergeSort(nums, mid + 1, end);		// �Ұ벿������
			Merge(nums, start, mid, end);		// �ϲ�������������
		}
	}


	// 5. ��������
	// ������������ѡ��Ԫ����ʹ�����Ԫ�ض�С����Ԫ���ұ�Ԫ�ض�������Ԫ
	int Partition(vector<int> &nums, int start, int end) {
		int key = nums[start];  // ��ѡ�����Ԫ����Ϊ��Ԫ
		int i = start, j = end;
		while (i < j) {
			while (key < nums[j] && i < j) j--;  // �����Ҷ˿�ʼ��ǰ�ѣ�����С��keyֹͣ
			if (i < j) {
				nums[i] = nums[j];
				i++;
			}
			while (key > nums[i] && i < j) i++;
			if (i < j) {
				nums[j] = nums[i];
				j--;
			}
		}  // ������i��Ϊkey����ȷλ��
		nums[i] = key;
		return i;
	}

	// �ݹ�ؽ��п���
	void QuickSort(vector<int> &nums, int start, int end) {
		if (start < end) {
			int k = Partition(nums, start, end);
			QuickSort(nums, start, k - 1);
			QuickSort(nums, k + 1, end);
		}
	}

};


int main() {
	// ���Ը�������������ʱ��

	// �������n����������
	vector<int> nums;
	int n = 1000;
	for (int i = 0; i < n; i++) nums.push_back(rand() % n);
	vector<int> nums1(nums);
	vector<int> nums2(nums);
	vector<int> nums3(nums);
	vector<int> nums4(nums);
	vector<int> nums5(nums);
	vector<int> nums6(nums);
	Sort so;

	// ��ʱ
	time_t s, e;
	double cost1, cost2, cost3, cost4, cost5, cost6;

	time(&s);
	so.BubbleSort(nums1);
	time(&e);
	cost1 = difftime(e, s);

	time(&s);
	so.SelectSort(nums2);
	time(&e);
	cost2 = difftime(e, s);

	time(&s);
	so.InsertSort(nums3);
	time(&e);
	cost3 = difftime(e, s);

	time(&s);
	so.InsertSort2(nums4);
	time(&e);
	cost4 = difftime(e, s);

	time(&s);
	so.MergeSort(nums5, 0, n - 1);
	time(&e);
	cost5 = difftime(e, s);

	time(&s);
	so.QuickSort(nums6, 0, n - 1);
	time(&e);
	cost6 = difftime(e, s);

	cout << "ð������:  " << cost1 << "s" << endl;
	cout << "ѡ������:  " << cost2 << "s" << endl;
	cout << "��������:  " << cost3 << "s" << endl;
	cout << "��������2: " << cost4 << "s" << endl;
	cout << "�鲢����:  " << cost5 << "s" << endl;
	cout << "��������:  " << cost6 << "s" << endl;

}