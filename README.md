# ⚡ PULSE — Global Emergency GIS Dispatch & AVL Tree Navigation System

<p align="center">
  <img src="pulse-dashboard.jpg" alt="PULSE Emergency GIS Dispatcher Dashboard" width="100%">
</p>

<p align="center">
  <strong>Intelligent Emergency Dispatch | Geospatial Intelligence | Advanced Data Structures</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Project-PULSE-00BFFF?style=for-the-badge">
  <img src="https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus">
  <img src="https://img.shields.io/badge/Frontend-HTML5-orange?style=for-the-badge&logo=html5">
  <img src="https://img.shields.io/badge/Mapping-Leaflet-199900?style=for-the-badge&logo=leaflet">
  <img src="https://img.shields.io/badge/Status-Academic%20Prototype-success?style=for-the-badge">
</p>

---

## 🌐 Project Overview

**PULSE (Global Emergency GIS Dispatch & AVL Tree Navigation System)** is an interactive emergency medical dispatch application designed to demonstrate the integration of Geographic Information Systems (GIS), advanced data structures, geospatial algorithms, and intelligent navigation technologies.

The system combines interactive satellite mapping, patient address geocoding, self-balancing AVL Tree hospital indexing, Haversine distance calculations, ambulance movement simulation, and real-time browser-based voice guidance.

PULSE explores how algorithmic efficiency and geographical intelligence can support emergency response coordination through an integrated web application and C++ algorithm implementation.

---

## 🔗 Live Application & Repository

- 🌐 **Live Web Application:** [Launch PULSE](https://25a31a05hh.github.io/PULSE/)
- 📦 **GitHub Repository:** [25A31A05HH/PULSE](https://github.com/25A31A05HH/PULSE)

---

## 👨‍💻 Developer & Architect

| Category | Details |
|---|---|
| Developer | **Surimalla Venkata Tejaswi** |
| Project Name | PULSE |
| Project Domain | GIS & Emergency Dispatch |
| Core Data Structure | Self-Balancing AVL Tree |
| Algorithm Implementation | C++ |
| Frontend Technologies | HTML5, CSS3, JavaScript |
| Mapping Framework | Leaflet.js |
| Deployment Platform | GitHub Pages |
| Project Year | 2026 |

**Project Objective:** To demonstrate the practical application of data structures, geographical computation, and interactive mapping in an emergency dispatch environment.

---

# 🚀 Core Features

## 1. 🛰️ Esri High-Resolution Satellite Map Engine

- Integrates Esri World Imagery for satellite-based geographical visualization.
- Supports multiple map layers, including Satellite, Dark Mode, and OpenStreetMap.
- Provides interactive zooming, panning, and navigation.
- Enables operators to identify emergency locations visually.
- Supports click-to-pin patient location selection.
- Allows patient markers to be repositioned interactively.

## 2. 📍 Patient Address Input & Geocoding

- Supports full street addresses, landmarks, and location names.
- Integrates the Nominatim geocoding service.
- Converts human-readable addresses into geographical latitude and longitude coordinates.
- Supports manual GPS coordinate entry.
- Enables location selection directly through the interactive map.

**Example Location:** Bhanugudi Junction, Kakinada.

## 3. 🌳 Self-Balancing AVL Tree Core

PULSE demonstrates AVL Tree-based hospital indexing for efficient data organization and retrieval.

**Key capabilities:**

- Self-balancing Binary Search Tree implementation.
- Efficient node insertion and searching.
- Dynamic tree height calculation.
- Balance factor monitoring.
- Automatic tree balancing.
- Four AVL Tree rotation mechanisms:
  - LL — Left Left Rotation
  - RR — Right Right Rotation
  - LR — Left Right Rotation
  - RL — Right Left Rotation
- Tree height and rotation metrics.

### AVL Tree Time Complexity

| Operation | Complexity |
|---|---|
| Search | O(log N) |
| Insertion | O(log N) |
| Deletion | O(log N) |
| Traversal | O(N) |

AVL Trees maintain logarithmic height, supporting efficient indexed data retrieval.

## 4. 🚑 Telemetry & Emergency Dispatch Routing

- Calculates geographical distances between patient locations and candidate hospitals.
- Implements the Haversine formula for great-circle distance estimation.
- Supports proximity-based hospital selection.
- Visualizes dispatch paths through map polylines.
- Simulates ambulance movement from hospital to patient location.
- Displays geographical and dispatch telemetry.

## 5. 🔊 Web Speech API Voice Guidance

PULSE incorporates browser-based speech synthesis for voice-assisted dispatch demonstrations.

- Text-to-speech announcements.
- Dispatch decision notifications.
- Audio-based navigation guidance.
- Hands-free voice announcements where supported by the browser.

## 6. 📊 Interactive Telemetry Dashboard

The dashboard presents important system information, including:

- Patient geographical coordinates.
- Hospital indexing information.
- AVL Tree height.
- Rotation event metrics.
- Distance calculations.
- Dispatch details.
- Route visualization.
- Ambulance movement simulation.

---

# 🏗️ System Architecture & Workflow

PULSE follows a structured emergency dispatch workflow consisting of six major stages.

```text
             ┌───────────────────────────────────┐
             │  1. Emergency Call / Operator      │
             │     Address Search / GPS Input    │
             └─────────────────┬─────────────────┘
                               │
                               ▼
             ┌───────────────────────────────────┐
             │  2. Geocoding Engine               │
             │     Nominatim Address Conversion  │
             │     Latitude / Longitude          │
             └─────────────────┬─────────────────┘
                               │
                               ▼
             ┌───────────────────────────────────┐
             │  3. GIS Mapping Engine             │
             │     Leaflet + Esri Satellite       │
             │     Patient Location Visualization│
             └─────────────────┬─────────────────┘
                               │
                               ▼
             ┌───────────────────────────────────┐
             │  4. AVL Tree Hospital Indexing     │
             │     Hospital Data Organization    │
             │     Self-Balancing Operations     │
             └─────────────────┬─────────────────┘
                               │
                               ▼
             ┌───────────────────────────────────┐
             │  5. Distance & Routing Engine      │
             │     Haversine Distance Calculation│
             │     Dispatch Route Visualization  │
             └─────────────────┬─────────────────┘
                               │
                               ▼
             ┌───────────────────────────────────┐
             │  6. Emergency Dispatch Interface   │
             │     Ambulance Movement Simulation │
             │     Voice Guidance & Telemetry    │
             └───────────────────────────────────┘
```

---

# 🧮 Key Algorithms & Technical Concepts

## A. AVL Tree Algorithm

An AVL Tree is a self-balancing Binary Search Tree in which the height difference between the left and right subtrees of every node is at most one.

**Balance Factor Formula:**

```cpp
Balance Factor = Height(Left Subtree) - Height(Right Subtree)
```

A node is balanced when its balance factor is -1, 0, or +1.

When an imbalance occurs, the AVL Tree performs the appropriate rotation to restore balance.

## B. Haversine Distance Formula

The Haversine formula calculates the great-circle distance between two geographical coordinates on Earth's surface.

\[
a = \sin^2\left(\frac{\Delta\phi}{2}\right)
+\cos(\phi_1)\cos(\phi_2)
\sin^2\left(\frac{\Delta\lambda}{2}\right)
\]

\[
d = 2R\arctan2(\sqrt{a},\sqrt{1-a})
\]

Where:

- R = Earth's mean radius.
- φ₁ and φ₂ = Latitudes in radians.
- λ₁ and λ₂ = Longitudes in radians.
- d = Great-circle distance.

## C. Geocoding Algorithm

The Nominatim geocoding service converts human-readable location descriptions into geographical coordinates.

This allows operators to search for locations without manually entering GPS coordinates.

---

# 🛠️ Technologies & Tools Used

| Technology | Application |
|---|---|
| C++ | AVL Tree and algorithm implementation |
| HTML5 | Web application structure |
| CSS3 | Dashboard design and styling |
| JavaScript | Application logic and interactions |
| Leaflet.js | Interactive GIS mapping |
| Esri World Imagery | Satellite visualization |
| OpenStreetMap | Geographical map data |
| Nominatim | Address geocoding |
| Haversine Formula | Geographical distance calculation |
| Web Speech API | Voice announcements |
| Git & GitHub | Version control and source code management |
| GitHub Pages | Web application deployment |

---

# 📁 Project Directory Structure

```text
PULSE/
│
├── index.html
│   └── Single-File Interactive GIS Web Application
│
├── pulse.cpp
│   └── C++ Core Engine (AVL Tree & Algorithm Logic)
│
├── PULSE_Professional_15_Slide_Presentation.pptx
│   └── Professional 15-Slide Project Presentation
│
├── README.md
│   └── Project Documentation & System Architecture
│
└── pulse-dashboard.jpg
    └── Emergency Dispatch Dashboard Screenshot
```

---

# ⚙️ Installation & Execution

## 1. Access the Live Web Application

Visit the deployed application:

**[Launch PULSE](https://25a31a05hh.github.io/PULSE/)**

## 2. Clone the GitHub Repository

```bash
git clone https://github.com/25A31A05HH/PULSE.git
```

Navigate to the project directory:

```bash
cd PULSE
```

## 3. Run the Web Application

Open `index.html` in a modern web browser.

Alternatively, use a local development server such as VS Code Live Server.

## 4. Compile the C++ Core

Ensure that a C++ compiler such as GCC or MinGW is installed.

Compile:

```bash
g++ pulse.cpp -o pulse
```

Run on Windows:

```bash
pulse.exe
```

Run on Linux/macOS:

```bash
./pulse
```

---

# 🎯 Potential Applications & Use Cases

- Emergency medical dispatch coordination.
- Hospital proximity analysis.
- Geographical information systems.
- Location-based service applications.
- Ambulance dispatch simulation.
- Data Structures and Algorithms education.
- Geospatial data visualization.
- Algorithmic performance demonstrations.

---

# 🔮 Future Enhancements

Potential improvements to PULSE include:

- Integration with verified hospital databases.
- Real-time hospital bed availability.
- Live GPS tracking through connected ambulance devices.
- Road-network-based shortest-path routing.
- Traffic-aware ambulance route optimization.
- Backend API integration.
- Secure patient information management.
- Multi-user emergency operator dashboards.
- Integration with authorized emergency response services.

---

# ⚠️ Disclaimer

PULSE is an **academic prototype and portfolio demonstration** developed to explore the integration of GIS mapping, AVL Trees, geographical distance calculations, and emergency dispatch concepts.

It is not a certified emergency medical dispatch platform and has not been validated for real-world emergency medical operations.

The Haversine formula estimates straight-line geographical distance and does not independently determine the fastest road route. Hospital availability, ambulance locations, road travel times, and medical response decisions must be verified through authorized services before operational use.

---

# 📜 License & Credits

**Designed, Architected, and Developed by Susmitha Bandela.**

PULSE is an independently developed academic and portfolio project.

### Third-Party Technologies & Acknowledgements

- [Esri](https://www.esri.com/) — Satellite imagery and mapping services.
- [Leaflet](https://leafletjs.com/) — Interactive mapping framework.
- [OpenStreetMap](https://www.openstreetmap.org/) — Open geographical map data.
- [Nominatim](https://nominatim.org/) — Address geocoding services.
- Web Speech API — Browser-based speech synthesis.

Third-party technologies and geographical data remain subject to their respective licenses, attribution requirements, and usage policies.

### Project Information

| Category | Details |
|---|---|
| Project | PULSE |
| Developer | Susmitha Bandela |
| Year | 2026 |
| Domain | GIS & Emergency Dispatch |
| Core Language | C++ |
| Frontend | HTML, CSS & JavaScript |
| Project Status | Academic Prototype / Portfolio Demonstration |

---

<p align="center">
  <strong>⚡ PULSE — Connecting Location Intelligence with Emergency Response.</strong>
</p>

<p align="center">
  Developed with dedication by <strong>Susmitha Bandela</strong>
</p>

<p align="center">
  ⭐ If you find this project interesting, consider starring the repository!
</p>
