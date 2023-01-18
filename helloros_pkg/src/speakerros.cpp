#include <ros/ros.h>
#include <std_msgs/String.h> //Cabeçalho do tipo de mensagem string
#include <string>

int main (int argc, char** argv){
    ros::init(argc, argv,"speakerros");
    ros::NodeHandle nh;

    ros::Rate loop_rate(5);

    ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("carlinhos",1000); //Criando objeto publisher

    int count = 0;
    while(ros::ok()){
        std::string txt = "Hello, ROS! Contando em: " + std::to_string(count);

        ROS_INFO("%s", txt.c_str());

        std_msgs::String dado; //Instanciando/criando o tipo de mensagem para receber a informação
        dado.data = txt; //Armazenando a informação no atributo .data do objeto de tipo de mensagem instanciado
        chatter_pub.publish(dado); //Publicando no tópico "carlinhos" a informação armazenada em "dado" pelo publisher "chatter_pub"

        ros::spinOnce();
        loop_rate.sleep();
        ++count;

    }


    ROS_INFO_STREAM("Goodbye, ROS!");
    return 0;
}