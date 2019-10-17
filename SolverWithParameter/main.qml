import QtQuick 1.0

Rectangle {
    width: 400
    height: 200
    z: -69

    Rectangle {
        id: rectangle1
        x: 16
        y: 85
        width: 108
        height: 53
        color: "#ffffff"
        radius: 0
        z: 0
        border.width: 5
        border.color: "#11bea1"
        visible: true
    }


    Rectangle {
        id: rectangle2
        x: 148
        y: 86
        width: 105
        height: 53
        color: "#ffffff"
        radius: 0
        border.color: "#11bea1"
        visible: true
        border.width: 5
        z: 0
    }

    Rectangle {
        id: rectangle3
        x: 276
        y: 85
        width: 105
        height: 53
        color: "#ffffff"
        radius: 0
        border.color: "#11bea1"
        visible: true
        border.width: 5
        z: 0
    }

    TextInput {
        id: text_input1
        x: 16
        y: 88
        width: 108
        height: 48
        text: qsTr("Input start point")
        horizontalAlignment: TextInput.AlignHCenter
        transformOrigin: Item.Center
        z: 0
        font.family: "Comic Sans MS"
        font.pixelSize: 13

        property string hasData: "y"
    }

    TextInput {
        id: text_input2
        x: 148
        y: 88
        width: 105
        height: 48
        text: qsTr("Input end point")
        horizontalAlignment: TextInput.AlignHCenter
        rotation: 360
        transformOrigin: Item.Center
        font.family: "Comic Sans MS"
        font.pixelSize: 13

        property string hasData: "y"
    }

    TextInput {
        id: text_input3
        x: 276
        y: 88
        width: 105
        height: 48
        text: qsTr("Input params")
        font.family: "Comic Sans MS"
        horizontalAlignment: TextInput.AlignHCenter
        font.pixelSize: 13

        property string hasData: "y"
    }

    Text {
        id: label1
        x: 16
        y: 41
        width: 108
        height: 27
        text: qsTr("Start point")
        font.family: "Comic Sans MS"
        font.pixelSize: 16
    }

    Text {
        id: label2
        x: 148
        y: 41
        width: 105
        height: 27
        text: qsTr("End point")
        font.family: "Comic Sans MS"
        font.pixelSize: 16
    }

    Text {
        id: label3
        x: 276
        y: 41
        width: 105
        height: 27
        text: qsTr("Params")
        font.pixelSize: 16
        font.family: "Comic Sans MS"
    }




}
