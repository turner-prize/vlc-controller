from flask import Flask
import win32gui
import win32api

app = Flask(__name__)

def windowEnumerationHandler(hwnd, top_windows):
	top_windows.append((hwnd, win32gui.GetWindowText(hwnd)))

def VLCPlayPause():
	results = []
	top_windows = []
	win32gui.EnumWindows(windowEnumerationHandler, top_windows)
	for i in top_windows:
		if "vlc media" in i[1].lower():
			win32gui.SetForegroundWindow(i[0])
			win32api.keybd_event(0x20,0,)

@app.route("/")
def hello():
	VLCPlayPause()
	return "Hello World!"
 
if __name__ == "__main__":
    app.run(host='0.0.0.0')
