

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick
import QtQuick.Controls
import ClueJays
import QtQuick.Studio.Components 1.0

Rectangle {
    id: ui
    width: 1250
    height: 720
    color: Constants.backgroundColor

    Rectangle {
        id: rectangle
        x: 837
        y: 0
        width: 413
        height: 720
        color: "#414141"
    }

    Rectangle {
        id: checklistbackground
        x: 0
        y: 0
        width: 246
        height: 720
        color: "#414141"
    }

    Image {
        id: sideBar
        x: 0
        y: 0
        width: 246
        height: 720
        source: "images/Side Bar.png"
        fillMode: Image.PreserveAspectFit

        CheckBox {
            id: suspectbox1
            x: 154
            y: 104
            width: 40
            height: 30
            text: qsTr("Checkbox")
            scale: 0.6
            autoExclusive: false
            display: AbstractButton.IconOnly
            tristate: true
            checkState: Qt.Unchecked
        }

        CheckBox {
            id: suspectbox2
            x: 154
            y: 125
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: suspectbox3
            x: 154
            y: 146
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: suspectbox4
            x: 154
            y: 167
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: suspectbox5
            x: 154
            y: 188
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: suspectbox6
            x: 154
            y: 209
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: weaponbox1
            x: 154
            y: 287
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: weaponbox2
            x: 154
            y: 308
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: weaponbox3
            x: 154
            y: 329
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: weaponbox4
            x: 154
            y: 350
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: weaponbox5
            x: 154
            y: 371
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: weaponbox6
            x: 154
            y: 392
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: roombox1
            x: 154
            y: 470
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: roombox2
            x: 154
            y: 491
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: roombox3
            x: 154
            y: 512
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: roombox4
            x: 154
            y: 533
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: roombox5
            x: 154
            y: 554
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: roombox6
            x: 154
            y: 575
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: roombox7
            x: 154
            y: 596
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: roombox8
            x: 154
            y: 617
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        CheckBox {
            id: roombox9
            x: 154
            y: 638
            width: 40
            height: 30
            text: qsTr("Checkbox")
            tristate: true
            scale: 0.6
            display: AbstractButton.IconOnly
            checkState: Qt.Unchecked
            autoExclusive: false
        }

        Rectangle {
            id: s_cover1
            x: 134
            y: 111
            width: 22
            height: 122
            color: "#DBEEEA"
        }

        Rectangle {
            id: s_cover2
            x: 192
            y: 111
            width: 22
            height: 122
            color: "#DBEEEA"
        }

        Rectangle {
            id: w_cover3
            x: 134
            y: 294
            width: 22
            height: 122
            color: "#E1CDE6"
        }

        Rectangle {
            id: w_cover4
            x: 192
            y: 294
            width: 22
            height: 122
            color: "#E1CDE6"
        }

        Rectangle {
            id: r_cover5
            x: 134
            y: 477
            width: 22
            height: 185
            color: "#FAE1E5"
        }

        Rectangle {
            id: r_cover6
            x: 192
            y: 477
            width: 22
            height: 185
            color: "#FAE1E5"
        }
    }

    Image {
        id: centerScreen
        x: 246
        y: 0
        width: 591
        height: 720
        source: "images/Center Screen.png"
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: terminal
        x: 837
        y: 0
        width: 413
        height: 103
        source: "images/Terminal.png"
        fillMode: Image.PreserveAspectFit
    }
}
