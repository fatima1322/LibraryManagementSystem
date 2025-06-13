#include "NotificationManager.h"

void NotificationManager::send(const std::string& userID, const std::string& message) {
    std::cout << "[Notification] To: " << userID << " - " << message << std::endl;
}

void NotificationManager::notifyReservationAvailable(const std::string& resourceID, const std::string& userID) {
    std::string msg = "Your reserved item (ID: " + resourceID + ") is now available for pickup.";
    send(userID, msg);
}

void NotificationManager::notifyOverdue(const std::string& userID, const std::string& resourceID, int daysOverdue) {
    std::string msg = "Reminder: Your loan of item (ID: " + resourceID + ") is overdue by " +
                      std::to_string(daysOverdue) + " days.";
    send(userID, msg);
}
