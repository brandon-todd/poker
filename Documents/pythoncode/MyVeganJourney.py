import matplotlib.pylab as plt
from datetime import datetime
import mysql.connector

bmi = mysql.connector.connect(
    host = '127.0.0.1',
    user = 'btodd',
    password = 'Seahawksbdrizzle1',
    database = 'Vegan'
)

mycursor = bmi.cursor(buffered = True)
cursor = bmi.cursor(buffered = True)

ask = input("Do you want to input a weight today?(y/n)")
if ask == 'y':
    weight = input("What is your weight today?")

    today = datetime.today()
    date = today.strftime('%m/%d/%Y')
    mysql = "INSERT INTO weights(Dates, Weights) VALUES(%s,%s)"
    val = [date, weight]
    mycursor.execute(mysql,val)
    bmi.commit()
else:
    
    plot_dates, plot_weight = [], []
    cursor.execute("SELECT * FROM Vegan.weights")
    records = cursor.fetchall()
    [plot_weight.append(row[1]) for row in records]
    [plot_dates.append(row[0]) for row in records]
    print(plot_dates,plot_weight)

    plt.style.use('seaborn')
    fig, ax = plt.subplots()
    ax.scatter(plot_dates, plot_weight, c = 'blue', s = 20)
    plt.xticks(plot_dates, rotation = 15)

    ax.set_title('My Vegan Journey')
    ax.set_xlabel('Date', fontsize = 10)
    ax.set_ylabel('Weight(lbs)', fontsize = 16)
    ax.tick_params(axis = 'both', which = 'major', labelsize = 10)

    plt.show()