#!/usr/bin/env python3
import argparse
import shutil
import subprocess
import sys
from pathlib import Path

DEFAULT_URL = "https://www.bilibili.com/video/BV1Pi4y137HF/"


def build_command(url: str, output_dir: Path, cookies: str | None) -> list[str]:
    command = [
        "yt-dlp",
        "--format",
        "bestvideo*+bestaudio/best",
        "--merge-output-format",
        "mp4",
        "--output",
        str(output_dir / "%(title)s [%(id)s].%(ext)s"),
        url,
    ]
    if cookies:
        command.extend(["--cookies", cookies])
    return command


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Download a Bilibili video with yt-dlp (optional cookies support)."
    )
    parser.add_argument(
        "--url",
        default=DEFAULT_URL,
        help=f"Video URL to download (default: {DEFAULT_URL})",
    )
    parser.add_argument(
        "--output-dir",
        default="downloads",
        help="Output directory (default: downloads)",
    )
    parser.add_argument(
        "--cookies",
        help="Path to cookies.txt for login-required videos",
    )
    args = parser.parse_args()

    output_dir = Path(args.output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)

    if args.cookies and not Path(args.cookies).is_file():
        print(f"Error: cookies file not found: {args.cookies}", file=sys.stderr)
        return 1

    if shutil.which("yt-dlp") is None:
        print(
            "Error: yt-dlp not found in PATH. Install it with: python -m pip install -U yt-dlp",
            file=sys.stderr,
        )
        return 1

    command = build_command(args.url, output_dir, args.cookies)
    print("Running:", " ".join(command))
    result = subprocess.run(command, check=False)
    if result.returncode != 0:
        print("Download failed. See yt-dlp error output above.", file=sys.stderr)
    return result.returncode


if __name__ == "__main__":
    raise SystemExit(main())
