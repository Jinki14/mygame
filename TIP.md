# 💡 프로젝트 참고 메모 (TIP.md)

## ✅ 현재 디렉터리 구조 점검
📂 상위 디렉터리: `mygame`

| 폴더/파일           | 설명                                      |
|---------------------|-------------------------------------------|
| `build/`            | ✅ 빌드 결과물 저장 (예: `test.exe`)       |
| `data/`             | ✅ 저장된 JSON 데이터 파일                  |
| `external/`         | ✅ 외부 라이브러리 (`json.hpp` 등)         |
| `include/`          | ✅ 모든 클래스의 헤더 파일 (.h) 모음       |
| `src/`              | ✅ 실제 구현 소스 파일 (.cpp)              |
| `makefile`          | ✅ 빌드 자동화 설정 (아주 굿!)              |
| `README.md`         | ✅ 프로젝트 설명 문서                       |
| `TIP.md`            | 💡 추가 메모용 문서                        |

---

## ✅ 기본 디렉터리 구조 (C++ 프로젝트 기준)

```
mygame/
├── include/ 👉 헤더 파일 (.h)
│ ├── Character.h
│ ├── Weapon.h
│ ├── Part.h
│ ├── Skill.h
│ ├── Stat.h
│ ├── ElementType.h
│ └── CharacterInfo.h
│
├── src/ 👉 소스 파일 (.cpp)
│ ├── Character.cpp
│ ├── Weapon.cpp
│ ├── Part.cpp
│ ├── Skill.cpp
│ ├── main.cpp
│
├── data/ 👉 저장 파일 (json, txt 등)
│ └── character.json
│
├── build/ 👉 빌드 출력 디렉토리
│ └── test.exe
│
├── external/ 👉 외부 라이브러리 (json.hpp 등)
│ └── json.hpp
│
├── makefile 👉 (선택) 빌드 자동화용
├── CMakeLists.txt 👉 (선택) CMake 빌드 스크립트
├── README.md 👉 프로젝트 설명 문서
├── TIP.md 👉 유용한 정보 메모
```
---