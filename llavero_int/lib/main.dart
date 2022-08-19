import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';

import 'Views/fitness_app/fitness_app_home_screen.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  //Se inicia Firebase al momento de abri la aplicacion
  await Firebase.initializeApp();
  //Se abre la aplicacion desde MyApp
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  // Widget principal de la aplicacion

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Llavero inteligente',
      theme: ThemeData(
        primarySwatch: Colors.green,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      //Envia a la vista principal
      home: FitnessAppHomeScreen(),
    );
  }
}

class HexColor extends Color {
  //Clase con colores a utilizar en la aplicacion
  HexColor(final String hexColor) : super(_getColorFromHex(hexColor));

  static int _getColorFromHex(String hexColor) {
    hexColor = hexColor.toUpperCase().replaceAll('#', '');
    if (hexColor.length == 6) {
      hexColor = 'FF' + hexColor;
    }
    return int.parse(hexColor, radix: 16);
  }
}
