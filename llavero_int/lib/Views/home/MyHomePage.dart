import 'package:flutter/material.dart';
import 'package:firebase_database/firebase_database.dart';
import 'package:llavero_int/Views/DeviceViews/ConfigDeviceView.dart';
import 'package:llavero_int/Views/DeviceViews/UseDeviceView.dart';

import '../DeviceViews/NewDeviceView.dart';
import '../DeviceViews/UseDeviceView.dart';
import '../fitness_app/fitness_app_home_screen.dart';

class MyHomePage extends StatefulWidget {
  MyHomePage({Key? key, required this.title}) : super(key: key);
  final String title;

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage>
    with SingleTickerProviderStateMixin {
  late TabController _controller;
  DatabaseReference reference =
      FirebaseDatabase.instance.ref().child("ledStatus");
  @override
  void initState() {
    super.initState();
    _controller = TabController(length: 4, vsync: this, initialIndex: 1);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("CKeyI"),
        actions: [
          IconButton(icon: Icon(Icons.search), onPressed: () {}),
          PopupMenuButton<String>(
            onSelected: (value) {
              print(value);
            },
            itemBuilder: (BuildContext contesxt) {
              return [
                PopupMenuItem(
                  child: Text("Nuevo dispositivo"),
                  value: "Nuevo dispositivo",
                ),
                PopupMenuItem(
                  child: Text("Configurar dispositivos"),
                  value: "Configurar dispositivo",
                ),
                PopupMenuItem(
                  child: Text("App web"),
                  value: "App web",
                ),
                PopupMenuItem(
                  child: Text("Enviar correo"),
                  value: "Enviar correo",
                ),
                PopupMenuItem(
                  child: Text("Configuracion"),
                  value: "Configuracion",
                ),
              ];
            },
          )
        ],
        bottom: TabBar(
          controller: _controller,
          indicatorColor: Colors.white,
          tabs: [
            Tab(
              icon: Icon(Icons.camera_alt),
            ),
            Tab(
              text: "USAR DISPOSITIVO",
            ),
            Tab(
              text: "VER DISPOSITIVOS",
            ),
            Tab(
              text: "NUEVO DISPOSITIVOS",
            ),
          ],
        ),
      ),
      body: TabBarView(
        controller: _controller,
        children: [
          UseDeviceView(title: 'Encender inalambrico'),
          NewDeviceView(),
          ConfigDeviceView(),
          FitnessAppHomeScreen(),
        ],
      ),
    );
  }
}
