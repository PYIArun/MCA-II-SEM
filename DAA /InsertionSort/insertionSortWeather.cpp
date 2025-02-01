#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm> 

using namespace std;

struct WeatherData {
    string city;
    string timeStamp;
    double temperature;
};


void insertionSort(vector<WeatherData>& data) {
    for (int i = 1; i <= data.size()-1; i++) {
        WeatherData key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j].city > key.city) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
}

vector<WeatherData> generateWeatherData(int numSamples) {
    vector<string> cities = {"Delhi", "Bangalore", "Mumbai", "Chennai", "Kolkata"};
    vector<string> times = {"5:00 AM", "6:00 AM", "7:00 AM", "8:00 AM", "9:00 AM", 
                            "10:00 AM", "11:00 AM", "12:00 PM", "1:00 PM", "2:00 PM"};
    vector<WeatherData> data;

    for (int i = 0; i < numSamples; ++i) {
        WeatherData record;
        record.city = cities[rand() % cities.size()];
        record.timeStamp = times[rand() % times.size()];
        record.temperature = 20 + (rand() % 20);
        data.push_back(record);
    }

    sort(data.begin(), data.end(), [](const WeatherData& a, const WeatherData& b) {
        return a.timeStamp < b.timeStamp;
    });

    return data;
}

void printWeatherData(const vector<WeatherData>& data) {
    cout << setw(5) << "S.No." << setw(15) << "City" << setw(15) << "Time Stamp" << setw(15) << "Temp. (C)" << endl;
    for (int i = 0; i <= data.size()-1; i++) {
        cout << setw(5) << i + 1 << setw(15) << data[i].city << setw(15) << data[i].timeStamp << setw(15) << fixed << setprecision(1) << data[i].temperature << endl;
    }
}

int main() {
    // Generate weather data with at least 100 samples
    vector<WeatherData> weatherData = generateWeatherData(100);

    // Print the input data sorted by time
    cout << "Input Data (Sorted by Time):" << endl;
    printWeatherData(weatherData);

    // Sort the data by city using Insertion Sort
    insertionSort(weatherData);

    // Print the output data sorted by city
    cout << "\nOutput Data (Sorted by City):" << endl;
    printWeatherData(weatherData);

    return 0;
}
