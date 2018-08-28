// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SMARTCASH_CONSENSUS_CONSENSUS_H
#define SMARTCASH_CONSENSUS_CONSENSUS_H

#include <stdint.h>

/** The maximum allowed size for a serialized block, in bytes (only for buffer size limits) */
static const unsigned int MAX_BLOCK_SERIALIZED_SIZE = 2000000;
/** The maximum allowed multiple for the computed block size */
static const unsigned int MAX_BLOCK_SIZE_INCREASE_MULTIPLE = 2;
/** The number of blocks to consider in the computation of median block size */
static const unsigned int NUM_BLOCKS_FOR_MEDIAN_BLOCK = 2016;
/** The maximum allowed size for a serialized block, in bytes (network rule) */
static unsigned int maxBlockSize = 1000000;
/** The old block size limit */
static const unsigned int OLD_MAX_BLOCK_SIZE = 1000000;
static const unsigned int MAX_BLOCK_BASE_SIZE = 1000000;
/** The maximum allowed number of signature check operations in a block (network rule) */
static const int64_t MAX_BLOCK_SIGOPS_COST = 160000;
/** The maximum allowed number of signature check operations in a block (network rule) */
static unsigned int maxBlockSigops = maxBlockSize/50;
/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
static const int COINBASE_MATURITY = 100;
/** Version 1.0 net start block*/
static const int HF_V1_0_START_HEIGHT = 90000;
/** Smartnode start block*/
static const int HF_V1_1_SMARTNODE_HEIGHT = 300000;
/** Reject zerocoin in/outputs starting with this block */
static const int HF_ZEROCOIN_DISABLE = 266765;
/** SmartRewards automation start time*/
static const int HF_V1_2_START_VALIDATION_HEIGHT = 450000;
static const int HF_V1_2_START_HEIGHT = 525000; // 1 here to not trigger the new hive split instantly. before 07/25/2018 @ 7:00am (UTC)

static const int HF_V1_2_NODES_PER_BLOCK        = 10;
static const int HF_V1_2_NODES_BLOCK_INTERVAL   = 4;

/** SmartCash max reward block */
static const int HF_CHAIN_REWARD_END_HEIGHT = 717499999;

/** Testnets 1.2 payment start block*/
static const int TESTNET_V1_2_PAYMENTS_HEIGHT = 1000;
static const int TESTNET_V1_2_MULTINODE_PAYMENTS_HEIGHT_1 = 28500;
static const int TESTNET_V1_2_MULTINODE_PAYMENTS_HEIGHT_2 = 30300;

static const int TESTNET_V1_2_NODES_PER_BLOCK_1        = 3;
static const int TESTNET_V1_2_NODES_BLOCK_INTERVAL_1   = 6;
static const int TESTNET_V1_2_NODES_PER_BLOCK_2        = 3;
static const int TESTNET_V1_2_NODES_BLOCK_INTERVAL_2   = 3;

inline unsigned int MaxBlockSigOps()
{
    return MAX_BLOCK_SERIALIZED_SIZE / 50;
}

/** Flags for nSequence and nLockTime locks */
enum {
    /* Interpret sequence numbers as relative lock-time constraints. */
    LOCKTIME_VERIFY_SEQUENCE = (1 << 0),

    /* Use GetMedianTimePast() instead of nTime for end point timestamp. */
    LOCKTIME_MEDIAN_TIME_PAST = (1 << 1),
};

#endif // SMARTCASH_CONSENSUS_CONSENSUS_H
