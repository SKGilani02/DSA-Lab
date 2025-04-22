#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

class GarageSystem {
private:
    int road[MAX];    // Queue
    int garage[MAX];  // Stack

    int roadFront, roadRear;
    int garageTop;

public:
    GarageSystem() {
        roadFront = roadRear = -1;
        garageTop = -1;
    }

    // Queue functions
    bool isRoadEmpty() {
        return roadFront == -1;
    }

    bool isRoadFull() {
        return (roadRear + 1) % MAX == roadFront;
    }

    void enqueueRoad(int truck_id) {
        if (isRoadFull()) return;
        if (isRoadEmpty()) {
            roadFront = roadRear = 0;
        } else {
            roadRear = (roadRear + 1) % MAX;
        }
        road[roadRear] = truck_id;
    }

    int frontRoad() {
        return isRoadEmpty() ? -1 : road[roadFront];
    }

    void dequeueRoad() {
        if (isRoadEmpty()) return;
        if (roadFront == roadRear) {
            roadFront = roadRear = -1;
        } else {
            roadFront = (roadFront + 1) % MAX;
        }
    }

    // Stack functions
    bool isGarageFull() {
        return garageTop == MAX - 1;
    }

    bool isGarageEmpty() {
        return garageTop == -1;
    }

    void pushGarage(int truck_id) {
        if (!isGarageFull()) {
            garage[++garageTop] = truck_id;
        }
    }

    int topGarage() {
        return isGarageEmpty() ? -1 : garage[garageTop];
    }

    void popGarage() {
        if (!isGarageEmpty()) {
            garageTop--;
        }
    }

    // Operations
    void On_road(int truck_id) {
        enqueueRoad(truck_id);
    }

    void Enter_garage(int truck_id) {
        if (!isRoadEmpty() && frontRoad() == truck_id) {
            pushGarage(truck_id);
            dequeueRoad();
        } else {
            cout << "Error: " << truck_id << " NO. Vehicle cannot enter into garage.\n";
        }
    }

    void Exit_garage(int truck_id) {
        if (!isGarageEmpty() && topGarage() == truck_id) {
            cout << truck_id << " No. vehicle leaving garage\n";
            popGarage();
        } else {
            cout << "Error: " << truck_id << " No. Vehicle cannot exit garage.\n";
        }
    }

    void Show_trucks(const string& place) {
        if (place == "road") {
            cout << "Road Vehicle: ";
            if (isRoadEmpty()) {
                cout << "Empty\n";
                return;
            }
            int i = roadFront;
            while (true) {
                cout << road[i];
                if (i == roadRear) break;
                cout << "_";
                i = (i + 1) % MAX;
            }
            cout << endl;
        } else if (place == "garage") {
            cout << "Garage Vehicle: ";
            if (isGarageEmpty()) {
                cout << "Empty\n";
                return;
            }
            for (int i = 0; i <= garageTop; ++i) {
                cout << garage[i];
                if (i < garageTop) cout << "_";
            }
            cout << endl;
        }
    }
};

// Run fixed input exactly as shown in your picture
int main() {
    GarageSystem gs;

    gs.On_road(2);
    gs.On_road(5);
    gs.On_road(10);
    gs.On_road(9);
    gs.On_road(22);

    gs.Show_trucks("road");
    gs.Show_trucks("garage");

    gs.Enter_garage(2);

    gs.Show_trucks("road");
    gs.Show_trucks("garage");

    gs.Enter_garage(10);
    gs.Enter_garage(5);

    gs.Exit_garage(2);
    gs.Exit_garage(5);

    gs.Show_trucks("garage");

    return 0;
}

