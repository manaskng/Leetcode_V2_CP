class RideSharingSystem {
public:
    queue<int> rider;
    queue<int> driver;
    set<int> riderset;
    set<int> driverset;

    RideSharingSystem() {}

    void addRider(int riderId) {
        rider.push(riderId);
        riderset.insert(riderId);
    }

    void addDriver(int driverId) {
        driver.push(driverId);
        driverset.insert(driverId);
    }

    vector<int> matchDriverWithRider() {
        // find valid driver
        while (!driver.empty() && !driverset.count(driver.front())) {
            driver.pop();
        }

        // find valid rider
        while (!rider.empty() && !riderset.count(rider.front())) {
            rider.pop();
        }

        if (driver.empty() || rider.empty()) {
            return {-1, -1};
        }

        int d = driver.front();
        int r = rider.front();

        driver.pop();
        rider.pop();

        driverset.erase(d);
        riderset.erase(r);

        return {d, r};
    }

    void cancelRider(int riderId) {
        riderset.erase(riderId);  
    }
};
