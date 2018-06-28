<?php
//https://www.wikihow.com/Develop-an-IRC-Bot
$server = 'localhost'
$port = 8080;
$name = 'Harry-bot'
$ident = 'ubot'
$gecos = 'Harry-bot v6.66'
$channel = '#test'

//Connection
$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
$error = socket_connect($socket, $server, $port);
//Errors
if ($socket === false)
{
	$err_code = socket_last_error();
	$err_string = socket_strerror($err_code);
	die("Error $err_code: $err_string\n");
}
//Register the bot infos (\r\n = norme)
socket_write($socket, "NICK $name\r\n");
socket_write($socket, "USER $ident * 8 :$gecos\r\n");

//Boucle de la vie
while (is_ressource($socket))
{
	//Recupère et écrit les datas
	$data = trim(socket_read($socket, 1024, PHP_NORMAL_READ));
	echo $data . "\n";
	$d = explode(' ', $data);		//Split
	$d = array_pad($d, 10, ''); 	//Avoid ugly undifined errors

	//Gère les pings (obligatoire pour pas se faire kick)
	//On renvoi le même message avec PONG à la place de PING
	if ($d[0] == 'PING')
		socket_write($socket, 'PONG ' . $d[1] . "\r\n");
	//On joint le serveur sur $channel (on peut en mettre plusieurs avec des ',')
	//376/422 codes du message du jour pour savoir si on peut rentrer
	if ($d[1] === '376' || $d[1] === '422')
		socket_write($socket, 'JOIN ' . $channel . "\r\n")

	//Répond "Moooooo" aux messages
	if ($d[3] == ':@moo')	//@moo = nom de la commande
	{
		$moo = "M" . str_repeat("o", mt_rand(2, 15)); //Genere un Mooo
		socket_write($socket, 'PRIVMSG' . $d[2] . " :$moo\r\n"); //Envoi le message
	}
}
?>