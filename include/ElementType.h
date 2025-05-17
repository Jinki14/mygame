//#ifndef ELEMENT_TYPE_H
//#define ELEMENT_TYPE_H
#pragma once

enum class ElementType {
    Pyro, Hydro, Electro, Anemo, Cryo, Geo, Dendro, // 7원소 Phos(빛) 추가?
    Physical, // 물리
    None // 무속성
};

// 속성을 글자로 변환
inline std::string elementToString(ElementType element) {
    switch (element) {
        case ElementType::Pyro: return "불";
        case ElementType::Hydro: return "물";
        case ElementType::Electro: return "번개";
        case ElementType::Anemo: return "바람";
        case ElementType::Cryo: return "얼음";
        case ElementType::Geo: return "바위";
        case ElementType::Dendro: return "풀";
        case ElementType::Physical: return "물리";
        default: return "무속성";
    }
}
//#endif