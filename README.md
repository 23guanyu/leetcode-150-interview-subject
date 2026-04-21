# LeetCode 面试题集

这个仓库是我的LeetCode面试题集，包含了150道精选的面试题目解答和分析（C语言实现），涵盖从数据结构基础到算法进阶的多种题型。
（正在更新中）

## 目录

- [开始使用](#开始使用)
- [下载 Bilibili 视频（yt-dlp）](#下载-bilibili-视频yt-dlp)
- [题目列表](#题目列表)
- [如何贡献](#如何贡献)
- [版本控制](#版本控制)
- [作者](#作者)
- [鸣谢](#鸣谢)

## 开始使用

要开始学习和练习这些题目，你可以克隆这个仓库并在本地环境中尝试解答。以下是获取和运行这些题解的步骤。

### 先决条件

请确保你的计算机上安装了以下软件：
- Git
- 适用于解答题目的编程语言环境（比如 Python、Java或JavaScript）

### 安装

克隆这个仓库到本地：

```bash
git clone https://github.com/23guanyu/leetcode-150-interview-subject.git
```
进入仓库目录：
```bash
cd leetcode-150-interview-subject
```

现在你可以开始浏览题目和它们的解答了。

## 下载 Bilibili 视频（yt-dlp）

如果你需要将 `BV1Pi4y137HF` 下载到本地，可使用仓库内的跨平台 Python 脚本（底层调用 `yt-dlp`）。

### 安装依赖

1. 安装 Python 3  
2. 安装 `yt-dlp`：

```bash
python -m pip install -U yt-dlp
```

3. 建议安装 `ffmpeg`（用于音视频合并，`yt-dlp` 下载 `bestvideo+bestaudio` 时需要）  
   - macOS: `brew install ffmpeg`
   - Ubuntu/Debian: `sudo apt install ffmpeg`
   - Windows: `winget install Gyan.FFmpeg`

### 示例命令

```bash
python scripts/download_bilibili.py --url "https://www.bilibili.com/video/BV1Pi4y137HF/"
```

### 可选：使用 cookies（登录视频/会员视频常见）

先从浏览器导出 `cookies.txt`，然后：

```bash
python scripts/download_bilibili.py --url "https://www.bilibili.com/video/BV1Pi4y137HF/" --cookies ./cookies.txt
```

### 常见问题

- 需要登录才能下载：使用 `--cookies` 传入登录后的 `cookies.txt`。  
- 地区限制（geo restriction）：请确认视频在你所在地区可访问。  
- 画质选择：脚本默认 `bestvideo*+bestaudio/best`，优先最高质量。  
- 音视频分离：脚本已使用 `--merge-output-format mp4`，需确保 `ffmpeg` 可用。

## 题目列表

[1.合并两个数组](1merge2array)

[2.移除元素](2removeElements)

[3.删除有序数组中的重复项](3removeDuplicates)

## 如何贡献

如果你想贡献题解或改进现有的解答，请遵循以下步骤：

1. Fork 这个仓库。
2. 创建你的特性分支 (`git checkout -b feature/AmazingFeature`)。
3. 提交你的更改 (`git commit -m 'Add some AmazingFeature'`)。
4. 推送到分支 (`git push origin feature/AmazingFeature`)。
5. 提交 Pull Request。

## 版本控制

本项目使用 Git 进行版本管理。你可以在仓库中查看当前可用的版本。

## 作者

* **你的名字** - *初始工作* - [23guanyu](https://github.com/23guanyu)

## 鸣谢

感谢所有为开源社区做出贡献的人，以及所有利用和支持这个项目的 LeetCode 练习者！
