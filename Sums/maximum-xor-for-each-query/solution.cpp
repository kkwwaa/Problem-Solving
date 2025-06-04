class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        // Инициализируем вектор для хранения префиксных XOR-ов
        // Размер на 1 больше, чтобы sm[0] = 0 (пустой префикс)
        vector<int> sm(nums.size() + 1, 0);
        
        // Вычисляем префиксные XOR-ы
        // sm[i] = nums[0] ^ nums[1] ^ ... ^ nums[i-1]
        for (int i = 0; i < nums.size(); i++) {
            sm[i + 1] = sm[i] ^ nums[i];
        }
        
        // Инициализируем вектор для ответа
        vector<int> k(nums.size());
        
        // Вычисляем максимальное число с maximumBit битами
        // Например, если maximumBit = 2, то maxNum = 2^2 - 1 = 3 (в двоичной: 11)
        int maxNum = (1 << maximumBit) - 1;
        
        // Для каждого префиксного XOR находим число k, которое даёт максимальный XOR
        // sm[i] ^ k <= maxNum, и k должно максимизировать sm[i] ^ k
        for (int i = 0; i < nums.size(); i++) {
            // k[i] = sm[длина - i] ^ maxNum
            // Это даёт максимальный XOR для текущего префикса
            k[i] = sm[nums.size() - i] ^ maxNum;
        }
        
        // Возвращаем результат
        // Поскольку нам нужен обратный порядок (как в условии задачи),
        // мы уже заполнили k в нужном порядке
        return k;
    }
};
