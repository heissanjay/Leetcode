struct CheckInRecord {
    std::string station;
    int time;
};

struct AggregatedRecord {
    double totalTravelTime = 0;
    int tripCount = 0;
};

class UndergroundSystem {
private:
    std::unordered_map<int, CheckInRecord> checkInRecords;
    std::unordered_map<std::string, std::unordered_map<std::string, AggregatedRecord>> travelInfo;

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, std::string stationName, int t) {
        checkInRecords[id] = { stationName, t };
    }
    
    void checkOut(int id, std::string stationName, int t) {
        CheckInRecord checkInRecord = checkInRecords[id];
        checkInRecords.erase(id);

        int travelTime = t - checkInRecord.time;
        travelInfo[checkInRecord.station][stationName].totalTravelTime += travelTime;
        travelInfo[checkInRecord.station][stationName].tripCount++;
    }
    
    double getAverageTime(std::string startStation, std::string endStation) {
        AggregatedRecord record = travelInfo[startStation][endStation];
        return record.totalTravelTime / record.tripCount;
    }
};
