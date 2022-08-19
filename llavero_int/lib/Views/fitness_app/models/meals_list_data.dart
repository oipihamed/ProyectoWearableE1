//Clases modelo para mostrar vista con imagenes y titulos en tarjetas de vista
class MealsListData {
  MealsListData({
    this.imagePath = '',
    this.titleTxt = '',
    this.startColor = '',
    this.endColor = '',
    this.meals,
    this.kacl = 0,
  });

  String imagePath;
  String titleTxt;
  String startColor;
  String endColor;
  List<String>? meals;
  int kacl;

  static List<MealsListData> tabIconsList = <MealsListData>[
    MealsListData(
      imagePath: 'assets/fitness_app/breakfast.png',
      titleTxt: 'Temp',
      kacl: 34,
      meals: <String>['Liquidos,', 'Bloqueador'],
      startColor: '#FA7D82',
      endColor: '#FFB295',
    ),
    MealsListData(
      imagePath: 'assets/fitness_app/lunch.png',
      titleTxt: 'Humedad',
      kacl: 40,
      meals: <String>['No Lluvia,', 'Paraguas,'],
      startColor: '#738AE6',
      endColor: '#5C5EDD',
    ),
    MealsListData(
      imagePath: 'assets/fitness_app/snack.png',
      titleTxt: 'Pulso',
      kacl: 10,
      meals: <String>['Ritmo OK', 'Presion OK'],
      startColor: '#FE95B6',
      endColor: '#FF5287',
    ),
    MealsListData(
      imagePath: 'assets/fitness_app/dinner.png',
      titleTxt: 'Distancia',
      kacl: 0,
      meals: <String>['Esta a:', '2 m'],
      startColor: '#6F72CA',
      endColor: '#1E1466',
    ),
  ];
}
