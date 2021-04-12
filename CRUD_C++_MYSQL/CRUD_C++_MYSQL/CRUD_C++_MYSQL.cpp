#include <iostream>
#include<conio.h>
#include <mysql.h>

using namespace std;
int q_estado;


void Crear_registro_marcas();
	void Crear_registro_productos();
void Leer_registro_marcas();
	void Leer_registro_productos();
void Actualizar_registro_marcas();
	void Actualizar_registro_productos();
void Borrar_registro_marcas();
	void Borrar_registro_productos();




	int main()
	{
		


		int op = 0, op1 = 0, op2 = 0;


		cout << "*****************MENU******************" << endl << endl;
		cout << "SELECCIONE LA TABLA QUE DESEA EDITAR:" << endl << endl;
		cout << "Marcas...............................1" << endl;
		cout << "Productos............................2" << endl;
		cout << "Salir................................3" << endl << endl;
		cin >> op;

		switch (op) {

		case 1: system("cls");

			cout << "*************Editar_Tabla_Marcas**************" << endl << endl;
			cout << "SELECCIONE LA OPERACION QUE DESEA REALIZAR..." << endl << endl;
			cout << "Crear registro.......................1" << endl;
			cout << "Leer registro........................2" << endl;
			cout << "Actualizar registro..................3" << endl;
			cout << "Borrar registro......................4" << endl;
			cout << "Regresar.............................5" << endl << endl;
			cin >> op1;

			switch (op1) {
			case 1: Crear_registro_marcas();
				break;
			case 2: Leer_registro_marcas();
				break;
			case 3: Actualizar_registro_marcas();
				break;
			case 4:  Borrar_registro_marcas();
				break;
			case 5: system("cls"); main();
				break;
			default:cout << "Usted ah ingresado una opcion no valida, por favor ingurese una opcion valida" << endl;
			}

		break;

		case 2:  system("cls");

			cout << "************Editar_Tabla_Productos************" << endl << endl;
			cout << "SELECCIONE LA OPERACION QUE DESEA REALIZAR..." << endl << endl;
			cout << "Crear registro.......................1" << endl;
			cout << "Leer registro........................2" << endl;
			cout << "Actualizar registro..................3" << endl;
			cout << "Borrar registro......................4" << endl;
			cout << "Regresar.............................5" << endl << endl;
			cin >> op2;

			switch (op2) {
			case 1: Crear_registro_productos();
				break;
			case 2: Leer_registro_productos();
				break;
			case 3: Actualizar_registro_productos();
				break;
			case 4:  Borrar_registro_productos();
				break;
			case 5: system("cls"); main();
				break;
			default:cout << "Usted ah ingresado una opcion no valida, por favor ingurese una opcion valida" << endl;
			}


		break;
		case 3: system("exit");
			break;
		default:cout << "Usted ah ingresado una opcion no valida, por favor ingurese una opcion valida" << endl;
		}


	}

	void Crear_registro_marcas(){

		MYSQL* conectar;
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_productos_marcas", 3306, NULL, 0);
	

		if (conectar) {

			string marca;
			cout << "Ingrese la marca:" << endl;
			cin >> marca;
			string insert = "insert into marcas(marca) values('" + marca + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(conectar, i);

			if (!q_estado) {
				cout << "Ingreso exitoso..." << endl;
			}
			else {
				cout << "error al ingresar..." << endl;
			}
		}
		else {
			cout << "error en la conexión..." << endl;
		}
		system("pause");	system("cls"); main();
	}
	void Crear_registro_productos(){

		MYSQL* conectar;
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_productos_marcas", 3306, NULL, 0);


		if (conectar) {

			string producto,idmarca,descripcion,preciocosto,precioventa,existencia,fecha;
			cout << "Ingrese el nombre del producto:" << endl;
			cin >> producto;
			cout << "Ingrese el ID de la marca:" << endl;
			cin >> idmarca;
			cout << "Ingrese la descripcion del producto:" << endl;
			cin >> descripcion;
			cout << "Ingrese el precio costo del producto:" << endl;
			cin >> preciocosto;
			cout << "Ingrese el precio de venta del producto:" << endl;
			cin >> precioventa;
			cout << "Ingrese la existencia del producto:" << endl;
			cin >> existencia;
			cout << "Ingrese la fecha de ingreso del producto en formato AA-MM-DD:" << endl;
			cin >> fecha;


			string insert = "insert into productos(productos,idmarca,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) values('" + producto + "','" + idmarca + "','" + descripcion + "','" + preciocosto + "','" + precioventa + "','" + existencia + "','" + fecha + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(conectar, i);

			if (!q_estado) {
				cout << "Ingreso exitoso..." << endl;
			}
			else {
				cout << "error al ingresar..." << endl;
			}
		}
		else {
			cout << "error en la conexión..." << endl;
		}
		system("pause");	system("cls"); main();
	}
	void Leer_registro_marcas(){

		system("cls");

		MYSQL* conectar;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_productos_marcas", 3306, NULL, 0);
	

		if (conectar) {

			string consulta = "select * from marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(conectar, c);
			if (!q_estado) {
				resultado = mysql_store_result(conectar);
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ", " << fila[1] << endl;


				}

			}
			else {
				cout << "error al consultar..." << endl;
			}
		}
		else {
			cout << "error en la conexión..." << endl;
		}
		system("pause");	system("cls"); main();
	}
	void Leer_registro_productos(){

		system("cls");

		MYSQL* conectar;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_productos_marcas", 3306, NULL, 0);


		if (conectar) {

			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(conectar, c);
			if (!q_estado) {
				resultado = mysql_store_result(conectar);
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << ", " << fila[7] << ", " << fila[8] << endl;


				}

			}
			else {
				cout << "error al consultar..." << endl;
			}
		}
		else {
			cout << "error en la conexión..." << endl;
		}
		system("pause");	system("cls"); main();
	}	
	void Actualizar_registro_marcas(){
	
		MYSQL* conectar;
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_productos_marcas", 3306, NULL, 0);


		if (conectar) {

			string marca;
			string idmarca;
			cout << "Ingrese la ID de la marca que desa actualizar:" << endl;
			cin >> idmarca;
			cout << "Ingrese la el nuevo registro:" << endl;
			cin >> marca;

			string update = "update db_productos_marcas.marcas set marca=('" + marca + "') where('" +idmarca + "')=id_marca";
			const char* i = update.c_str();
			q_estado = mysql_query(conectar, i);

			if (!q_estado) {
				cout << "Actualizacion exitosa..." << endl;
			}
			else {
				cout << "Error al Actualizar..." << endl;
			}
		}
		else {
			cout << "Error en la conexión..." << endl;
		}
	
		system("pause");	system("cls"); main();
	}
	void Actualizar_registro_productos(){
		MYSQL* conectar;
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_productos_marcas", 3306, NULL, 0);


		if (conectar) {

			string producto, idmarca, descripcion, preciocosto, precioventa, existencia, fecha,idproducto;

			cout << "Ingrese la ID del producto que desa actualizar:" << endl;
			cin >> idproducto;
			cout << "Ingrese el nombre del producto:" << endl;
			cin >> producto;
			cout << "Ingrese el ID de la marca:" << endl;
			cin >> idmarca;
			cout << "Ingrese la descripcion del producto:" << endl;
			cin >> descripcion;
			cout << "Ingrese el precio costo del producto:" << endl;
			cin >> preciocosto;
			cout << "Ingrese el precio de venta del producto:" << endl;
			cin >> precioventa;
			cout << "Ingrese la existencia del producto:" << endl;
			cin >> existencia;
			cout << "Ingrese la fecha de ingreso del producto en formato AA-MM-DD:" << endl;
			cin >> fecha;


			string insert = "update db_productos_marcas.productos set  productos =('" + producto + "'),idmarca =('" + idmarca + "'),descripcion =('" + descripcion + "' ), precio_costo = ('" + preciocosto + "'), precio_venta =('" + precioventa + "'), existencia =('" + existencia + "'), fecha_ingreso =('" + fecha + "')  where('" + idproducto + "') = idproductos";
			const char* i = insert.c_str();
			q_estado = mysql_query(conectar, i);

			if (!q_estado) {
				cout << "Ingreso exitoso..." << endl;
			}
			else {
				cout << "error al ingresar..." << endl;
			}
		}
		else {
			cout << "error en la conexión..." << endl;
		}
	
	
	
		system("pause");	system("cls"); main();
	
	}
	void Borrar_registro_marcas(){

		MYSQL* conectar;
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_productos_marcas", 3306, NULL, 0);


		if (conectar) {

			string marca;
			string idmarca;
			cout << "Ingrese la ID de la marca	que desea eliminar:" << endl;
			cin >> idmarca;
		
			string update = "delete from db_productos_marcas.marcas  where('" + idmarca + "')=id_marca";
			const char* i = update.c_str();
			q_estado = mysql_query(conectar, i);

			if (!q_estado) {
				cout << "Eliminacion exitosa..." << endl;
			}
			else {
				cout << "Error al eliminar..." << endl;
			}
		}
		else {
			cout << "Error en la conexión..." << endl;
		}
		system("pause");	system("cls"); main();
	}
	void Borrar_registro_productos(){
		MYSQL* conectar;
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_productos_marcas", 3306, NULL, 0);


		if (conectar) {

			string producto;
			string idproducto;
			cout << "Ingrese la ID del producto que desea eliminar:" << endl;
			cin >> idproducto;

			string update = "delete from db_productos_marcas.productos  where('" + idproducto + "')=idproductos";
			const char* i = update.c_str();
			q_estado = mysql_query(conectar, i);

			if (!q_estado) {
				cout << "Eliminacion exitosa..." << endl;
			}
			else {
				cout << "Error al eliminar..." << endl;
			}
		}
		else {
			cout << "Error en la conexión..." << endl;
		}
	
		system("pause");	system("cls"); main();
	}

