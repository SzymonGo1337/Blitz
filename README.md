# Blitz

![alt text](https://github.com/SzymonGo1337/Blitz/blob/main/banner.png?raw=true)

Blitz jest Framework'iem który ma na celu ułatwiać tworzenie aplikacji czy gier w C++'ie z użyciem OpenGL'a.
Jest on tworzony przez [Debug](https://github.com/SzymonGo1337)'a i [Komoda](https://github.com/K0M0D4)'ę.
Jako dwaj niezależni twórcy planujemy wiele rzeczy do naszego Framework'u.

## Instalacja

Proponuje do pobrania projektu użyć [git](https://git-scm.com/downloads)'a.

```bash
git clone https://github.com/SzymonGo1337/Blitz.git
git submodule update --recursive
```

## Użycie

```cpp
#include <Blitz/Blitz-Core.hpp>

int main(int argc, char** argv) {
	Blitz::Pause();
	Blitz::Exit();
}
```

## Licencja
[MIT](https://choosealicense.com/licenses/mit/)