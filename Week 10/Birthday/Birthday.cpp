#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Friend {
	size_t arriveTime;
	size_t leaveTime;
	size_t index;
};

struct Seat {
	size_t seatNumber;
	size_t freedAt;

	bool operator>(const Seat& other) const {
		return freedAt > other.freedAt;
	}
};

int main()
{
	int n;
	cin >> n;
	vector<Friend> friends(n);

	for (size_t i = 0; i < n; i++)
	{
		cin >> friends[i].arriveTime >> friends[i].leaveTime;
		friends[i].index = i;
	}

	sort(friends.begin(), friends.end(), [](const Friend& first, const Friend& second) {
		if (first.arriveTime == second.arriveTime)
			return first.leaveTime < second.leaveTime;
		return first.arriveTime < second.arriveTime;
		});

	size_t wantedFriendInd;
	cin >> wantedFriendInd;

	priority_queue<size_t, vector<size_t>, greater<size_t>> freeSeats;
	priority_queue<Seat, vector<Seat>, greater<Seat>> occupiedSeats;
	int wantedFriendSeat = -1;

	for (size_t i = 0; i < n; i++)
		freeSeats.push(i);

	for (Friend& f : friends)
	{
		while (!occupiedSeats.empty() && f.arriveTime >= occupiedSeats.top().freedAt)
		{
			freeSeats.push(occupiedSeats.top().seatNumber);
			occupiedSeats.pop();
		}

		if (f.index == wantedFriendInd)
		{
			wantedFriendSeat = freeSeats.top();
			break;
		}

		occupiedSeats.push({ freeSeats.top(), f.leaveTime });
		freeSeats.pop();
	}

	cout << wantedFriendSeat;
}
