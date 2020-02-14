#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Timestamp {
	double time;
	double displacement;
};

// Operator overload for sort from the algorithm library
bool operator< (const Timestamp &A, const Timestamp &B) {
	if (A.time < B.time)    return true;
	else    return false;
}

// Function for calculating the speed
double speed(int time1, int pos1, int time2, int pos2) {
	double time = double(time2) - double(time1);
	double pos = double(pos2) - double(pos1);

	return abs(pos/time);
}

int main() {
	int n;
	cin >> n;
	vector<Timestamp> TimeStamp;
	vector<double> TimeList;
	int temp1, temp2;
	for (int i = 0; i < n; ++i) {
		cin >> temp1;
		cin >> temp2;
        TimeStamp.emplace_back(Timestamp{ double(temp1), double(temp2) });
	}

	sort(TimeStamp.begin(), TimeStamp.end());

	for (int i = 0; i < n-1; ++i) {
	    double temp = speed(TimeStamp[i].time, TimeStamp[i].displacement, TimeStamp[i+1].time, TimeStamp[i + 1].displacement);
		TimeList.emplace_back(temp);
	}

	sort(TimeList.begin(), TimeList.end());

	cout << TimeList[n-2] << endl;

	return 0;
}