#ifndef ENGINE_EVENT_INCLUDE
#define ENGINE_EVENT_INCLUDE

#include <functional>
#include <unordered_map>

namespace Engine {

class Event {
private:
    std::unordered_map<
    std::string,
        std::unordered_map<
        std::string,
        std::function<void(void)>
        >
        >events;
public:
    void createEvent(const std::string& eventName) {
        try {
            events.at(eventName);
        } catch(std::out_of_range) {
            events[eventName] = std::unordered_map<std::string, std::function<void(void)>>();
        }
    }

    void addEvent(const std::string& eventName, const std::string& id, std::function<void(void)> function) {
        try {
            std::unordered_map<std::string, std::function<void(void)>> & map = events.at(eventName);
            try {
                map.at(id) = function;
            } catch(std::out_of_range) {
                map[id] = function;
            }
        } catch(std::out_of_range) {
            events[eventName] = std::unordered_map<std::string, std::function<void(void)>>();
            addEvent(eventName, id, function);
        }
    }

    void runEvent(const std::string& eventName) {
        try {
            for(auto function : events.at(eventName)) {
                function.second();
            }
        } catch(std::out_of_range) {
            std::cout << "ENGINE : Event " << eventName << " is not exists.\n";
        }
    }
};

};

#endif // ENGINE_EVENT_INCLUDE
