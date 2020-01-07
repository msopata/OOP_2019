import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

import pl.gwizdz 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TextField {
        id: textField
        x: 106
        y: 51
        width: 254
        height: 40
        text: "0"
    }

    Label {
        id: label
        x: 108
        y: 138
        width: 74
        height: 23
        text: "speed:"
    }
    /*
    Demo{
        id: demo
        value: 0.1
        onTest: textField.clear()

    }*/

    Button {
        id: button
        x: 395
        y: 51
        width: 150
        height: 40
        text: "Change"
        onClicked: function(){
            displacement.set( parseFloat(textField.text) )

        }
    }

    Label {
        id: label1
        x: 115
        y: 243
        width: 119
        height: 23
        text: "acceleration:"
    }

    Displacement{
        id: displacement
        onChanged: function(){
            console.log(displacement.value)
            speedValueLabel.text = speed.speed.toString()
            accelerationValueLabel.text = acceleration.acceleration.toString()
            speed.onDisplacementChange(this.get())
        }
    }

    Speed{
        id: speed
        speed: 0
        onChanged: acceleration.onSpeedChange(this.get())

    }

    Acceleration{
        id: acceleration
        acceleration: 0
    }

    Text {
        id: speedValueLabel
        x: 240
        y: 138
        width: 105
        height: 38
        text: speed.speed.toString();
        font.pixelSize: 12
    }

    Text {
        id: accelerationValueLabel
        x: 234
        y: 243
        width: 102
        height: 32
        text: acceleration.acceleration.toString();
        font.pixelSize: 12
    }

}
