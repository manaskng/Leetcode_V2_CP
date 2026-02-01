1class RideSharingSystem {
2public:
3    queue<int> rider;
4    queue<int> driver;
5    set<int> riderset;
6    set<int> driverset;
7
8    RideSharingSystem() {}
9
10    void addRider(int riderId) {
11        rider.push(riderId);
12        riderset.insert(riderId);
13    }
14
15    void addDriver(int driverId) {
16        driver.push(driverId);
17        driverset.insert(driverId);
18    }
19
20    vector<int> matchDriverWithRider() {
21        // find valid driver
22        while (!driver.empty() && !driverset.count(driver.front())) {
23            driver.pop();
24        }
25
26        // find valid rider
27        while (!rider.empty() && !riderset.count(rider.front())) {
28            rider.pop();
29        }
30
31        if (driver.empty() || rider.empty()) {
32            return {-1, -1};
33        }
34
35        int d = driver.front();
36        int r = rider.front();
37
38        driver.pop();
39        rider.pop();
40
41        driverset.erase(d);
42        riderset.erase(r);
43
44        return {d, r};
45    }
46
47    void cancelRider(int riderId) {
48        riderset.erase(riderId);  
49    }
50};
51