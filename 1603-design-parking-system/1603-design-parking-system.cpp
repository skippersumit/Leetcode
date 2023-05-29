class ParkingSystem {
public:
    int totalB, totalM, totalS;
    ParkingSystem(int big, int medium, int small) {
        totalB = big;
        totalM = medium;
        totalS = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            return totalB-- > 0 ? true : false;
        } else if( carType == 2 ) {
            return totalM-- > 0 ? true : false;
        } else {
            return totalS-- > 0 ? true : false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */