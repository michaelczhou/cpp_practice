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

	// 1. 冒泡排序
	void BubbleSort(vector<int> &nums) {
		int n = nums.size();
		for (int i = 1; i < n; i++) {  // i表示冒泡的趟数，至多需要n-1趟
			int flag = 0;  // flag表示某趟冒泡是否有交换元素
			for (int j = 0; j < n - i; j++) {
				if (nums[j] > nums[j + 1]) {
					swap(nums[j], nums[j + 1]);
					flag = 1;
				}
			}
			if (flag == 0) break;  // 某趟结束后判断是否发生交换
		}
	}

	// 2. 选择排序
	void SelectSort(vector<int> &nums) {
		int n = nums.size();
		for (int i = 0; i < n - 1; i++) {  // i表示无序序列最左端的元素
			int index = i;
			for (int j = i + 1; j < n; j++)  // 找出乱序序列中数值最小的下标
				if (nums[j] < nums[index])
					index = j;
			swap(nums[i], nums[index]);
		}
	}

	// 3. 插入排序
	// 3.1 直接插入排序
	void InsertSort(vector<int> &nums) {
		int n = nums.size();
		for (int i = 1; i < n; i++) {  // 从第二个元素开始，依次往前插入
			int tmp = nums[i], j = i - 1;
			for (; j >= 0 && tmp < nums[j]; j--)  // 寻找tmp的正确位置，不正确时遇到的元素后移
				nums[j + 1] = nums[j];
			nums[j + 1] = tmp;
		}
	}

	// 3.2 折半插入排序
	void InsertSort2(vector<int> &nums) {
		int n = nums.size();
		for (int i = 1; i < n; i++) {
			int tmp = nums[i];
			// 折半查找，返回时，low即为tmp的正确位置
			int high = i - 1, low = 0, mid;
			while (low <= high) {
				mid = (low + high) / 2;
				if (tmp < nums[mid]) high = mid - 1;
				else low = mid + 1;
			}
			// 将low后面的元素都往后移一位
			for (int j = i; j > low; j--) {
				nums[j] = nums[j - 1];
			}
			nums[low] = tmp;
		}
	}

	// 4. 归并排序
	// 辅助函数：合并两个有序序列，只给定起始位置，分界线，以及终点位置
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
		// 合并完成后，把结果放回nums中同一块区域
		for (int i = start; i <= end; i++) {
			nums[i] = ret[i - start];
		}
	}

	// 递归地进行归并
	void MergeSort(vector<int> &nums, int start, int end) {
		if (start < end) {
			int mid = (start + end) / 2;
			MergeSort(nums, start, mid);		// 左半部分有序
			MergeSort(nums, mid + 1, end);		// 右半部分有序
			Merge(nums, start, mid, end);		// 合并两个有序序列
		}
	}


	// 5. 快速排序
	// 辅助函数：挑选主元，并使得左边元素都小于主元，右边元素都大于主元
	int Partition(vector<int> &nums, int start, int end) {
		int key = nums[start];  // 挑选最左边元素作为主元
		int i = start, j = end;
		while (i < j) {
			while (key < nums[j] && i < j) j--;  // 从最右端开始往前搜，遇到小于key停止
			if (i < j) {
				nums[i] = nums[j];
				i++;
			}
			while (key > nums[i] && i < j) i++;
			if (i < j) {
				nums[j] = nums[i];
				j--;
			}
		}  // 结束后i即为key的正确位置
		nums[i] = key;
		return i;
	}

	// 递归地进行快排
	void QuickSort(vector<int> &nums, int start, int end) {
		if (start < end) {
			int k = Partition(nums, start, end);
			QuickSort(nums, start, k - 1);
			QuickSort(nums, k + 1, end);
		}
	}

};


int main() {
	// 测试各个方法的运行时间

	// 随机生成n个乱序数字
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

	// 计时
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

	cout << "冒泡排序:  " << cost1 << "s" << endl;
	cout << "选择排序:  " << cost2 << "s" << endl;
	cout << "插入排序:  " << cost3 << "s" << endl;
	cout << "插入排序2: " << cost4 << "s" << endl;
	cout << "归并排序:  " << cost5 << "s" << endl;
	cout << "快速排序:  " << cost6 << "s" << endl;

}