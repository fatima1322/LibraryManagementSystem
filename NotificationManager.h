#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <string>
#include <iostream>

class NotificationManager {
public:
    static void send(const std::string& userID, const std::string& message);
    static void notifyReservationAvailable(const std::string& resourceID, const std::string& userID);
    static void notifyOverdue(const std::string& userID, const std::string& resourceID, int daysOverdue);
};

#endif