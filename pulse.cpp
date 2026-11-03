#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory>
#include <iomanip>

// ============================================================================
// Pulse - Global Emergency GIS Dispatch & AVL Tree Core (C++ Backend)
// ============================================================================

struct Hospital {
    std::string name;
    std::string location;
    std::string specialty;
    double rating;
    double lat;
    double lng;

    void display() const {
        std::cout << "  [★ " << std::fixed << std::setprecision(1) << rating << "] " 
                  << std::left << std::setw(34) << name 
                  << " | (" << std::setw(15) << location << ")"
                  << " | Coords: [" << std::setw(8) << lat << ", " << std::setw(8) << lng << "]\n";
    }
};

// --- Self-Balancing AVL Tree Node ---
struct AVLNode {
    Hospital data;
    int height;
    std::shared_ptr<AVLNode> left;
    std::shared_ptr<AVLNode> right;

    AVLNode(const Hospital& h)
        : data(h), height(1), left(nullptr), right(nullptr) {}
};

// --- Self-Balancing AVL Tree Class for Hospital Ranking ---
class AVLTree {
private:
    std::shared_ptr<AVLNode> root;

    int getHeight(std::shared_ptr<AVLNode> node) const {
        return node ? node->height : 0;
    }

    int getBalanceFactor(std::shared_ptr<AVLNode> node) const {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    std::shared_ptr<AVLNode> rightRotate(std::shared_ptr<AVLNode> y) {
        auto x = y->left;
        auto T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    std::shared_ptr<AVLNode> leftRotate(std::shared_ptr<AVLNode> x) {
        auto y = x->right;
        auto T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    std::shared_ptr<AVLNode> insert(std::shared_ptr<AVLNode> node, const Hospital& h) {
        if (!node) {
            return std::make_shared<AVLNode>(h);
        }

        if (h.rating < node->data.rating) {
            node->left = insert(node->left, h);
        } else if (h.rating > node->data.rating) {
            node->right = insert(node->right, h);
        } else {
            return node; // Duplicate ratings handled gracefully
        }

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && h.rating < node->left->data.rating) {
            return rightRotate(node);
        }
        // Right Right Case
        if (balance < -1 && h.rating > node->right->data.rating) {
            return leftRotate(node);
        }
        // Left Right Case
        if (balance > 1 && h.rating > node->left->data.rating) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Right Left Case
        if (balance < -1 && h.rating < node->right->data.rating) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inOrderDescending(std::shared_ptr<AVLNode> node, std::vector<Hospital>& result) const {
        if (node) {
            inOrderDescending(node->right, result); // Highest rating first
            result.push_back(node->data);
            inOrderDescending(node->left, result);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void addHospital(const Hospital& h) {
        root = insert(root, h);
    }

    std::vector<Hospital> getRankedHospitals() const {
        std::vector<Hospital> result;
        inOrderDescending(root, result);
        return result;
    }
};

// --- Haversine Distance Calculation (Great-Circle Distance) ---
double calculateDistanceKm(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371.0; // Earth radius in kilometers
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    double a = std::sin(dLat / 2) * std::sin(dLat / 2) +
               std::cos(lat1 * M_PI / 180.0) * std::cos(lat2 * M_PI / 180.0) *
               std::sin(dLon / 2) * std::sin(dLon / 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return R * c;
}

// --- Main Global Dispatch Engine ---
int main() {
    std::cout << "====================================================================\n";
    std::cout << "     PULSE GLOBAL EMERGENCY GIS & AVL DISPATCH CORE (C++ ENGINE)    \n";
    std::cout << "====================================================================\n\n";

    AVLTree globalHospitalIndex;

    std::cout << "Indexing Global & Regional Facilities into Self-Balancing AVL Tree...\n";
    // Global & Regional Hospitals Database
    globalHospitalIndex.addHospital({"Mayo Clinic", "Rochester, USA", "Multi-Specialty Trauma", 4.95, 44.0224, -92.4678});
    globalHospitalIndex.addHospital({"Johns Hopkins Hospital", "Baltimore, USA", "Advanced Research & ICU", 4.92, 39.2973, -76.5922});
    globalHospitalIndex.addHospital({"Massachusetts General", "Boston, USA", "Level 1 Trauma Center", 4.90, 42.3626, -71.0692});
    globalHospitalIndex.addHospital({"AIIMS New Delhi", "New Delhi, India", "National Apex Trauma", 4.88, 28.5672, 77.2100});
    globalHospitalIndex.addHospital({"Government General (GGH)", "Kakinada, India", "Regional Trauma Care", 4.85, 16.9785, 82.2350});
    globalHospitalIndex.addHospital({"Apollo Reach", "Kakinada, India", "Critical Care Surgery", 4.80, 17.0021, 82.2565});
    globalHospitalIndex.addHospital({"Charité Hospital", "Berlin, Germany", "European Medical Center", 4.86, 52.5255, 13.3764});
    globalHospitalIndex.addHospital({"Singapore General", "Singapore", "Multi-Disciplinary ICU", 4.89, 1.2798, 103.8347});

    std::cout << "\n--------------------------------------------------------------------\n";
    std::cout << "GLOBAL AVL TREE RANKED DIRECTORY (Sorted by In-Order Traversal):\n";
    std::cout << "--------------------------------------------------------------------\n";
    auto rankedHospitals = globalHospitalIndex.getRankedHospitals();
    for (size_t i = 0; i < rankedHospitals.size(); ++i) {
        std::cout << "Rank #" << (i + 1) << " ->";
        rankedHospitals[i].display();
    }

    // Simulated Emergency Dispatch (Demo location: New Delhi Sector)
    double ambulanceBaseLat = 28.5562;
    double ambulanceBaseLng = 77.2088;
    double patientLat = 28.5600;
    double patientLng = 77.2150;

    std::cout << "\n--------------------------------------------------------------------\n";
    std::cout << "GLOBAL EMERGENCY DISPATCH SIMULATION:\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "  🚑 Ambulance Station Base : [" << ambulanceBaseLat << ", " << ambulanceBaseLng << "]\n";
    std::cout << "  📍 Patient Incident Pin   : [" << patientLat << ", " << patientLng << "]\n";

    // Select matching top-ranked facility (AIIMS or closest high-rated)
    Hospital targetHospital = rankedHospitals[3]; // AIIMS New Delhi
    std::cout << "  🏥 Selected Target Ward   : " << targetHospital.name << " (" << targetHospital.location << ") [★" << targetHospital.rating << "]\n";

    // Telemetry calculations
    double leg1Dist = calculateDistanceKm(ambulanceBaseLat, ambulanceBaseLng, patientLat, patientLng);
    double leg2Dist = calculateDistanceKm(patientLat, patientLng, targetHospital.lat, targetHospital.lng);
    double totalDistance = leg1Dist + leg2Dist;
    double estTimeMins = (totalDistance / 45.0) * 60.0;

    std::cout << "\n--------------------------------------------------------------------\n";
    std::cout << "ROUTE TELEMETRY METRICS:\n";
    std::cout << "--------------------------------------------------------------------\n";
    std::cout << "  Leg 1 (Base ➔ Patient)    : " << std::fixed << std::setprecision(2) << leg1Dist << " km\n";
    std::cout << "  Leg 2 (Patient ➔ Hospital): " << std::fixed << std::setprecision(2) << leg2Dist << " km\n";
    std::cout << "  Total Road Distance       : " << std::fixed << std::setprecision(2) << totalDistance << " km\n";
    std::cout << "  Estimated ETA             : " << std::ceil(estTimeMins) << " minutes\n";

    std::cout << "\n[✓] Pulse Global C++ Core Execution Completed Successfully.\n";
    return 0;
}
