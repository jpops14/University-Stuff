import requests
import matplotlib.pyplot as plt
import pandas as pd



# downloading covid data from this site was easier than from polish .gov site
cases_src = requests.get('https://covid.ourworldindata.org/data/owid-covid-data.csv') 
open('covid.csv', 'w').write(cases_src.text)
cases = pd.read_csv('covid.csv', encoding='ascii', header=0)
cases = cases.loc[cases['location'] == 'Poland']

# data on covid cases from web and cleaned up data on avg temperatures (from file shared on teams converted to csv, had trouble with txt)
temps=pd.read_csv('ex1-Popiel_avg_temps.csv', encoding='ascii', header=0, names=["date","temp"])

# picked this period because temperature data doesn't reach into 2021
wave_start = "2020-10-13"
wave_end   = "2020-11-30"

calm_start = "2020-08-21"
calm_end   = "2020-09-20"

# filter infection wave data
wave_cases = cases[(cases["date"] >= wave_start) & (cases["date"] <= wave_end)]        
wave_temps = temps[(temps["date"] >= wave_start) & (temps["date"] <= wave_end)]
# filter calm infection time interval data
calm_cases = cases[(cases["date"] >= calm_start) & (cases["date"] <= calm_end)]    
calm_temps = temps[(temps["date"] >= calm_start) & (temps["date"] <= calm_end)]

# plot init 
# graphs are put in a column instead of a row, because in row outlay they were way less readable
figure, axis = plt.subplots(2,1)  
# creating double graphs using twinx
x1 = axis[0]
twin1 = x1.twinx()
x2 = axis[1]
twin2 = x2.twinx()


# wave graph
x1.set_title("Infection wave")
x1.set_xlabel("Date")
x1.set_ylabel("Cases")
twin1.set_ylabel("Temperatures in ℃")
wave_cases.plot(x="date", y="new_cases", ax=x1, color="red",label="New cases")
wave_temps.plot(x="date", y="temp", ax=twin1, color="blue",label="Temperature")
x1.legend(loc="lower center", bbox_to_anchor=(0.5, 0.0))
twin1.legend(loc="lower center", bbox_to_anchor=(0.5, 0.1))

#calm graph
x2.set_title("Time period with lower infection rate")
x2.set_xlabel("Date")
x2.set_ylabel("Cases")
twin1.set_ylabel("Temperatures in ℃")
calm_cases.plot(x="date", y="new_cases", ax=x2, color="green",label="New cases")
calm_temps.plot(x="date", y="temp", ax=twin2, color="blue",label="Temperature")
x2.legend(loc="lower center", bbox_to_anchor=(0.5, 0.0))
twin2.legend(loc="lower center", bbox_to_anchor=(0.5, 0.1))

# display window

manager = plt.get_current_fig_manager()
manager.window.showMaximized()
manager.set_window_title("Comparison of temperatures and Covid infection rates")
plt.show()
