###### Документация по плагинам electron
https://www.electronjs.org/docs/latest/tutorial/native-code-and-electron

----

# @mobile-electron/focus 

**Активирует окно и возвращает фокус приложению** 

## Требования  
- `Node.js 20.18.0` или новее  
- `Electron 32.3.3` или новее  

#### Требования для разработки и сборки
- `Visual Studio 2022` или новее с инструментом `VC++ (Visual C++)`
- `Python  3.9.*`  или новее

## Публикация
Публикация по пути  ```name```  с версией указанной в ```version```. Публиковать нужно собранный плагин, а не только сорцы. 
```bash
    npm publish
```
## Публикация для боковой
Публикация с определенным **tag**( к примеру для разработки в боковой)
```bash
    npm publish --tag *Любой тег*
```
Затем установка будет идти
```bash
    npm install <package-name>@<tag>
```

## Поднятие версии
Версию поднимаем в ручную в ```version```