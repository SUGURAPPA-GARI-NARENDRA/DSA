import cv2
import json
import os
from datetime import datetime

# -----------------------------
# Global Variables
# -----------------------------
zones = []
drawing = False
start_point = None
temp_end_point = None
zone_id_counter = 1
fullscreen = False

ZONE_FILE = "zones.json"

colors = [
    (0, 255, 0),
    (255, 0, 0),
    (0, 0, 255),
    (255, 255, 0),
    (255, 0, 255),
    (0, 255, 255)
]

# -----------------------------
# AUTO DETECT WORKING CAMERA
# -----------------------------
def get_working_camera():
    for i in range(5):  # try first 5 indexes
        cap = cv2.VideoCapture(i, cv2.CAP_DSHOW)
        if cap.isOpened():
            print(f"Camera opened at index {i}")
            return cap
        cap.release()
    return None

# -----------------------------
# Load Zones
# -----------------------------
def load_zones():
    global zones, zone_id_counter
    if os.path.exists(ZONE_FILE):
        with open(ZONE_FILE, "r") as f:
            zones = json.load(f)
        if zones:
            zone_id_counter = max(z["id"] for z in zones) + 1

# -----------------------------
# Save Zones
# -----------------------------
def save_zones():
    with open(ZONE_FILE, "w") as f:
        json.dump(zones, f, indent=4)

# -----------------------------
# Mouse Draw
# -----------------------------
def draw_rectangle(event, x, y, flags, param):
    global drawing, start_point, temp_end_point, zone_id_counter

    if event == cv2.EVENT_LBUTTONDOWN:
        drawing = True
        start_point = (x, y)

    elif event == cv2.EVENT_MOUSEMOVE:
        if drawing:
            temp_end_point = (x, y)

    elif event == cv2.EVENT_LBUTTONUP:
        drawing = False
        end_point = (x, y)

        zone = {
            "id": zone_id_counter,
            "start": start_point,
            "end": end_point,
            "color": colors[(zone_id_counter - 1) % len(colors)],
            "created_at": datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        }

        zones.append(zone)
        zone_id_counter += 1
        save_zones()

# -----------------------------
# Check Inside Zone
# -----------------------------
def is_inside_zone(px, py, zone):
    x1, y1 = zone["start"]
    x2, y2 = zone["end"]
    return min(x1,x2) < px < max(x1,x2) and min(y1,y2) < py < max(y1,y2)

# -----------------------------
# MAIN FUNCTION
# -----------------------------
def main():
    global fullscreen

    cap = get_working_camera()

    if cap is None:
        print("❌ ERROR: No working camera found!")
        print("Check camera connection or close other apps using camera.")
        return

    load_zones()

    cv2.namedWindow("People Counter")
    cv2.setMouseCallback("People Counter", draw_rectangle)

    # HOG People Detector
    hog = cv2.HOGDescriptor()
    hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())

    while True:
        ret, frame = cap.read()
        if not ret:
            print("Frame read failed.")
            break

        total_people = 0
        zone_counts = {z["id"]: 0 for z in zones}

        # Detect People
        boxes, _ = hog.detectMultiScale(frame, winStride=(8,8))

        for (x, y, w, h) in boxes:
            cx = x + w // 2
            cy = y + h // 2

            total_people += 1
            cv2.rectangle(frame, (x,y), (x+w,y+h), (0,255,0), 2)

            for zone in zones:
                if is_inside_zone(cx, cy, zone):
                    zone_counts[zone["id"]] += 1

        # Draw Zones
        for zone in zones:
            x1, y1 = zone["start"]
            x2, y2 = zone["end"]
            color = zone["color"]

            cv2.rectangle(frame, (x1,y1), (x2,y2), color, 2)

            label = f"Zone {zone['id']} | Count: {zone_counts[zone['id']]}"
            cv2.putText(frame, label, (x1, y1 - 10),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.6, color, 2)

        # Temporary rectangle
        if drawing and temp_end_point:
            cv2.rectangle(frame, start_point, temp_end_point, (200,200,200), 1)

        # Total count
        cv2.putText(frame, f"Total People: {total_people}",
                    (20,40), cv2.FONT_HERSHEY_SIMPLEX,
                    1, (0,0,255), 2)

        # Instructions
        instructions = [
            "Draw: Mouse Drag",
            "Delete Last: D",
            "Reset: R",
            "Quit: Q"
        ]

        for i, text in enumerate(instructions):
            cv2.putText(frame, text, (20, 70 + i*25),
                        cv2.FONT_HERSHEY_SIMPLEX,
                        0.6, (255,255,255), 2)

        cv2.imshow("People Counter", frame)

        key = cv2.waitKey(1) & 0xFF

        if key == ord('q'):
            save_zones()
            break

        elif key == ord('d'):
            if zones:
                zones.pop()
                save_zones()

        elif key == ord('r'):
            zones.clear()
            save_zones()

    cap.release()
    cv2.destroyAllWindows()

# -----------------------------
if __name__ == "__main__":
    main()
