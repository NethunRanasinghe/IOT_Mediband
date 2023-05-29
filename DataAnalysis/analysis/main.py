import matplotlib.pyplot as plt
import firebase_admin
from firebase_admin import credentials
from firebase_admin import db
from datetime import datetime

def GetFirebaseValues():
    x_values = []
    y_values = []

    cred = credentials.Certificate("analysis\espfirebase-b20ba-firebase-adminsdk-v6o3n-e763673641.json")
    firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://espfirebase-b20ba-default-rtdb.firebaseio.com/'
    })
    ref = db.reference('Devices/OKBgM38OzbbEzgmKG9ZWBYoO7qD2')
    data = ref.get()

    for i in data.values():
        y_values.append(i['heartRate'])

        timedate = i['time']
        time_inputf = '%Y-%m-%d-%H-%M-%S'
        time_outputf = '%d-%H-%M'
        input_datetime = datetime.strptime(timedate, time_inputf)
        output_string = datetime.strftime(input_datetime, time_outputf)
        x_values.append(output_string)

    PlotGraph(x_values,y_values)

def PlotGraph(x_values,y_values):
    y = y_values
    x = x_values
    
    plt.figure('Long Term Data Analysis')

    plt.plot(x, y)

    plt.axhline(y=101, color='red', linestyle="--")
    plt.axhline(y=60, color='red', linestyle="--")

    plt.xlabel('Date')
    plt.ylabel('Heart Rate')
    plt.title('Long Term Heart Rate Monitoring')
    

    plt.ylim(0,110)
    plt.xticks(rotation=90, ha='right')
    plt.subplots_adjust(bottom=0.2)

    plt.axhspan(0,60, alpha=0.5, color='red')
    plt.axhspan(60,100, alpha=0.5, color='green')
    plt.axhspan(100,110, alpha=0.5, color='red')

    plt.text(x[0], 30, 'Low Heart Rate', color='red', fontsize=12, weight='bold')
    plt.text(x[0], 80, 'Normal Heart Rate', color='green', fontsize=12, weight='bold')
    plt.text(x[0], 105, 'High Heart Rate', color='red', fontsize=12, weight='bold')

    plt.show()

GetFirebaseValues()