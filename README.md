# ChangerStatusCpp
## Install
### Можно делать в корневой дерриктории проекта | You can do it in the root directory of the project
```
git clone https://github.com/discord/discord-rpc.git
cd discord-rpc
```
```
mkdir build
cd build
cmake ..
```
#### После этого пишем в косоль | After that, we write to the console <br>
`mv .clang-format .clang-format.backup` <br>
#### После данной команды нужено отредактировать файл по пути: | After this command, you need to edit the file along the path: <br>
`thirdparty/rapidjson-1.1.0/include/rapidjson/document.h` <br>
#### В этом файле найти строчку: | Find the line in this file: <br>
`GenericStringRef& operator=(const GenericStringRef& rhs) { s = rhs.s; length = rhs.length; }` <br>
#### Заменить на: | Replace with: <br>
`GenericStringRef& operator=(const GenericStringRef& rhs) { s = rhs.s; /* length = rhs.length; */ return *this; }`
#### После смело выполняем следующие действия | After that, we boldly perform the following actions <br>
```
make
sudo make install
```
#### После выполнения всех выше перечисленных манипуляций собираем проект, если вы его редактировали. | After performing all the above manipulations, we assemble the project, if you edited it. <br>

#### В корне ChangerStatusCpp | At the root of ChangerStatusCpp <br>
```
cd build
cmake ..
make
```
#### И запуск программы | And the launch of the program <br>
```
./CustomRP
```
