import 'package:firebase_database/firebase_database.dart';
import 'package:flutter/material.dart';

class UseDeviceView extends StatefulWidget {
  UseDeviceView({Key? key, required this.title}) : super(key: key);
  final String title;
  @override
  State<UseDeviceView> createState() => _UseDeviceViewState();
}

class _UseDeviceViewState extends State<UseDeviceView> {
  DatabaseReference reference =
      FirebaseDatabase.instance.ref().child("ledStatus");
  double ledOn = 0;

  double ledOff = 0;

  @override
  void initState() {
    super.initState();
    fireBaseData();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(
          widget.title,
          style: TextStyle(fontSize: 30),
        ),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Container(
              margin: EdgeInsets.all(30),
              decoration: BoxDecoration(
                borderRadius: BorderRadius.all(Radius.circular(50)),
                color: ledOn == 1 ? Colors.green : Colors.red,
              ),
              child: SizedBox(
                width: 100,
                height: 100,
              ),
            ),
            ElevatedButton(
              child: Text("Turn On the Led",
                  style: TextStyle(
                      color: Colors.white,
                      fontStyle: FontStyle.italic,
                      fontSize: 20.0)),
              onPressed: _turnOnLed,
            ),
            ElevatedButton(
              child: Text("Turn Off the Led",
                  style: TextStyle(
                      color: Colors.white,
                      fontStyle: FontStyle.italic,
                      fontSize: 20.0)),
              onPressed: _turnOffLed,
            ),
          ],
        ),
      ),
      // This trailing comma makes auto-formatting nicer for build methods.
    );
  }

  void _turnOnLed() {
    reference.update({
      'ledOn': 1,
    });

    reference.update({
      'ledOff': 0,
    });

    setState(() {
      ledOn = 1;
      ledOff = 0;
    });
  }

  void _turnOffLed() {
    reference.update({
      'ledOff': 1,
    });

    reference.update({
      'ledOn': 0,
    });

    setState(() {
      ledOn = 0;
      ledOff = 1;
    });
  }

  Future<void> fireBaseData() async {
    final snapshot = await reference.get();
    if (snapshot.value != null) {
      ledOn = double.parse(snapshot.child('ledOn').value.toString());

      ledOff = double.parse(snapshot.child('ledOff').value.toString());
    }
  }
}
