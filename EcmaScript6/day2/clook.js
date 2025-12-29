class Clock {
    #intervalId;

    constructor(timeStr) {
        const [h, m, s] = timeStr.split(":").map(Number);
        this.hours = h;
        this.minutes = m;
        this.seconds = s;
    }

    static formatTime(hours, minutes, seconds) {
        return [hours, minutes, seconds]
            .map(val => String(val).padStart(2, '0'))
            .join(':');
    }

    #tick() {
        this.seconds++;
        if (this.seconds >= 60) {
            this.seconds = 0;
            this.minutes++;
        }
        if (this.minutes >= 60) {
            this.minutes = 0;
            this.hours++;
        }
        if (this.hours >= 24) {
            this.hours = 0;
        }
        console.log(this.getTime());
    }

    start() {
        this.#intervalId = setInterval(() => this.#tick(), 1000);
    }

    stop() {
        clearInterval(this.#intervalId);
    }

    getTime() {
        return Clock.formatTime(this.hours, this.minutes, this.seconds);
    }
}

class AlarmClock extends Clock {
    #alarmTime;

    constructor(initialTime, alarmTime) {
        super(initialTime);
        this.#alarmTime = alarmTime;
    }

    #checkAlarm() {
        if (this.getTime() === this.#alarmTime) {
            console.log("ALARM! Wake up! 🔔");
            this.stop();
        }
    }

    start() {
        super.start();
        const originalTick = setInterval(() => {
            this.#checkAlarm();
            if (this.getTime() === this.#alarmTime) clearInterval(originalTick);
        }, 1000);
    }

    setAlarm(newAlarmTime) {
        this.#alarmTime = newAlarmTime;
        console.log(`Alarm updated to: ${this.#alarmTime}`);
    }
}
const myAlarm = new AlarmClock("07:59:55", "08:00:00");
myAlarm.start();
