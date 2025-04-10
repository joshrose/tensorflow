# Copyright 2023 The TensorFlow Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ==============================================================================

kFingerprintError: str
kFingerprintFound: str
kFingerprintNotFound: str

class MetricException(Exception): ...

def AddAsyncCheckpointWriteDuration(api_label: str, microseconds: float) -> None: ...
def AddCheckpointReadDuration(api_label: str, microseconds: float) -> None: ...
def AddCheckpointWriteDuration(api_label: str, microseconds: float) -> None: ...
def AddNumCheckpointShardsWritten(num_shards: int) -> None: ...
def AddShardingCallbackDuration(callback_duration: int) -> None: ...
def AddTrainingTimeSaved(api_label: str, microseconds: float) -> None: ...
def CalculateFileSize(arg0: str) -> int: ...
def GetAsyncCheckpointWriteDurations(api_label: str) -> bytes: ...
def GetCheckpointReadDurations(api_label: str) -> bytes: ...
def GetCheckpointSize(api_label: str, filesize: int) -> int: ...
def GetCheckpointWriteDurations(api_label: str) -> bytes: ...
def GetFoundFingerprintOnLoad() -> str: ...
def GetNumCheckpointShardsWritten() -> int: ...
def GetRead(write_version: str) -> int: ...
def GetReadApi(arg0: str) -> int: ...
def GetReadFingerprint() -> str: ...
def GetReadPath() -> str: ...
def GetReadPathAndSingleprint() -> tuple[str, str]: ...
def GetShardingCallbackDescription() -> str: ...
def GetShardingCallbackDuration() -> int: ...
def GetTrainingTimeSaved(api_label: str) -> int: ...
def GetWrite(write_version: str) -> int: ...
def GetWriteApi(arg0: str) -> int: ...
def GetWriteFingerprint() -> str: ...
def GetWritePath() -> str: ...
def GetWritePathAndSingleprint() -> tuple[str, str]: ...
def IncrementRead(write_version: str) -> None: ...
def IncrementReadApi(arg0: str) -> None: ...
def IncrementWrite(write_version: str) -> None: ...
def IncrementWriteApi(arg0: str) -> None: ...
def RecordCheckpointSize(api_label: str, filesize: int) -> None: ...
def SetFoundFingerprintOnLoad(found_status: str) -> None: ...
def SetReadFingerprint(fingerprint: bytes) -> None: ...
def SetReadPath(saved_model_path: str) -> None: ...
def SetReadPathAndSingleprint(path: str, singleprint: str) -> None: ...
def SetShardingCallbackDescription(description: str) -> None: ...
def SetWriteFingerprint(fingerprint: bytes) -> None: ...
def SetWritePath(saved_model_path: str) -> None: ...
def SetWritePathAndSingleprint(path: str, singleprint: str) -> None: ...
