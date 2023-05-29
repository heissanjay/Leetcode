class ParkingSystem {
private:
    int bigSpace, mediumSpace, smallSpace;
    int bigCnt, mediumCnt, smallCnt;
public:
    ParkingSystem(int big, int medium, int small) {
        this->bigSpace = big;
        this->mediumSpace = medium;
        this->smallSpace = small;
        
        // initial counts
        this->bigCnt = 0;
        this->mediumCnt = 0;
        this->smallCnt = 0;
    }
    
    bool addCar(int carType) {
        if (carType == 1) {
            if (this->bigCnt < this->bigSpace) {
                this->bigCnt++;
                return true;
            }else {
                return false;
            }
        } else if ( carType == 2) {
             if (this->mediumCnt < this->mediumSpace) {
                this->mediumCnt++;
                return true;
            }else {
                return false;
            }
        }  if (this->smallCnt < this->smallSpace) {
                this->smallCnt++;
                return true;
            }else {
                return false;
            }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */