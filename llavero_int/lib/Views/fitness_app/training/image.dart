import 'package:firebase_image/firebase_image.dart';
import 'package:flutter/material.dart';

import '../fitness_app_theme.dart';

class ImageFB extends StatefulWidget {
  ImageFB({Key? key}) : super(key: key);

  @override
  State<ImageFB> createState() => _ImageFBState();
}
//Clase para mostrar imagen obtenida de bd
class _ImageFBState extends State<ImageFB> {
  @override
  void initState() {
    super.initState();
    //Se inicializa la conexion a data storage de firebase
    FirebaseImage('gs://llaveroint.appspot.com/data/photo.jpg').preCache();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        body: Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        crossAxisAlignment: CrossAxisAlignment.center,
        children: [
          Container(
            decoration: BoxDecoration(
                gradient: LinearGradient(
              begin: Alignment.topRight,
              end: Alignment.bottomLeft,
              colors: [
                FitnessAppTheme.dark_grey,
                FitnessAppTheme.dark_grey.withOpacity(0.9),
                FitnessAppTheme.dark_grey.withOpacity(0.5),
              ],
              
            ),
             borderRadius: const BorderRadius.only(
                      topLeft: Radius.circular(8.0),
                      bottomLeft: Radius.circular(8.0),
                      bottomRight: Radius.circular(8.0),
                      topRight: Radius.circular(68.0)),),
            
          ),
          Image(
            //Imgene obtenida de la base de datos.
            image: FirebaseImage('gs://llaveroint.appspot.com/data/photo.jpg',
                shouldCache: true, // The image should be cached (default: True)
                maxSizeBytes: 3000 * 1000, // 3MB max file size (default: 2.5MB)
                cacheRefreshStrategy:
                    CacheRefreshStrategy.NEVER // Switch off update checking
                ),
            width: 400,
            height: 400,
          ),
        ],
      ),
    ));
  }
}
